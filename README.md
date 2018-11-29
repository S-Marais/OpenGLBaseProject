# OpenGLBaseProject
A base project to help anyone setting a working project using OpenGL, with glfw and glew.

## Disclaimer
This project is not a production ready project. Its main goal is to provide a working base out of the box for anyone trying to learn OpenGL.

The project is for not not Windows ready as it relies on Cmake AND make to set and manage the project.
I am working on a future version for all platforms.

## How-to
The project uses `git modules` for its dependencies so obviously you need `git` to be installed in order to download 
all the dependencies and dependency's dependencies.

in a `Terminal` enter the command below:
```bash
git clone --recursive https://github.com/S-Marais/OpenGLBaseProject.git OpenGLBaseProject
```
This will download this project as well as its dependencies and especially the ones for glew. (this will take some time).

Once this is done make sure `libs/glew` has an `include/GL` folder with `glew.h` and that this newly created folder is 
detected by your IDE.

If all went well you should be able to compile and run the project and see a window with a blue background.

## Informations
The generated binaries for this project and its dependencies are all packed in a `bin` folder. That includes third party
libraries like `glfw` and `glew`. For instance with CLion the folder is in `cmake-build-debug` or `cmake-build-release`.

All third party libraries are compiled as shared libraries.

Happy coding!

