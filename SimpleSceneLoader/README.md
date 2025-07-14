# SimpleSceneLoader

A basic OpenGL project to load and render simple scenes described in a text file.  
Each object has a position, size, and rotation, and is currently rendered as a colored cube.

## ✨ Features
- Loads a scene description from file (with type, position, size, rotation)
- Uses modern OpenGL (GLFW + GLAD + GLSL shaders)
- Basic camera movement (WASD + mouse look)
- Renders multiple cubes with transformations


## 🛠 Build & Run

Make sure you have:
- OpenGL 3.3 compatible GPU
- [GLFW](https://www.glfw.org/)
- [GLAD](https://glad.dav1d.de/) (or generated `glad.c` in your project)
- GLM (for math)

**In Visual Studio:**
1. Clone this repository:
    ```bash
    git clone https://github.com/yourusername/SimpleSceneLoader.git
    ```
2. Open the `.sln` or create a new project and add the files.
3. Make sure your include / lib directories for GLFW, GLAD, and GLM are set.
4. Build & run.

**Controls:**
- `W/A/S/D` : move camera
- mouse : look around
- scroll : zoom in/out
- `ESC` : exit

## 📄 Scene File Format
Each line describes an object. Each feature of an object is seperated by tabs. Type only accepts cube for now. Position, Size, and Rotation accept 3 numerical values seperated by a single space. Example format is in the file.

## 📌 TODO / Planned
- Add textures to objects
- Support different object types
- Lighting