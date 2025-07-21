#version 330 core

uniform vec3 userColor;
uniform float intensity;
out vec4 FragColor;

void main() {
	FragColor = vec4(userColor, 1.0) * intensity;
}

