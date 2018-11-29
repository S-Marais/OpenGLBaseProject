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

Once this is done 