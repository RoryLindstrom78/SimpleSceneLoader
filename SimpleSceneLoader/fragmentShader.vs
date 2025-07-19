#version 330 core

out vec4 FragColor;

in vec3 FragPos;
in vec2 TexCoord;
in vec3 Normal;

uniform sampler2D texture_diffuse1; // Fixed name
uniform vec3 viewPos;

struct PointLight {
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

#define NR_POINT_LIGHTS 32
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform int numPointLights;

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 textureColor);

void main()
{
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 textureColor = texture(texture_diffuse1, TexCoord).rgb;

    vec3 result = vec3(0.0);

    if (numPointLights > 0) {
        for (int i = 0; i < numPointLights; ++i) {
            result += CalcPointLight(pointLights[i], norm, FragPos, viewDir, textureColor);
        }
    } else {
        // simple ambient fallback (texture only)
        result = 0.3 * textureColor;
    }

    FragColor = vec4(result, 1.0);
}

// Lighting calculation for a single point light
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir, vec3 textureColor)
{
    vec3 lightDir = normalize(light.position - fragPos);
    float diff = max(dot(normal, lightDir), 0.0);

    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0); // hardcoded shininess

    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    

    vec3 ambient  = light.ambient  * textureColor;
    vec3 diffuse  = light.diffuse  * diff * textureColor;
    vec3 specular = light.specular * spec; // optional: multiply by texture if using specular map

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return ambient + diffuse + specular;
}
