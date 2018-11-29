#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(int argc, char **argv) {
    /// We are setting up a basic lambda function so that glfw can send us error messages when needed
    glfwSetErrorCallback([](int error, const char *message){
        std::cerr << "[ GLFW Error ] ( " << error << " ) : " << message << std::endl;
    })

    /// We initialize glfw and exiting is something went wrong. glfwInit reply true or false if it was
    /// successful. most errors should be sent to error callback so we exit the app since we have nothing
    /// left to do here
    if (!glfwInit()) {
        std::cerr << "[ GLFW Error ] : Failed to initialize glfw!\nExiting ..." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    /// Now we can specify some window parameters such as the OpenGL targeted version and so on.
    /// Apple only had support for OpenGL 4.1 and needed a forward compatibility to work.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

    /// Let's not create a window that we will be able to use.
    GLFWwindow *window = glfwCreateWindow(860, 540, "OpenGL Base Project", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "[ GLFW Error ] : Failed to create a window!\nExiting ..." << std::endl;
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    /// Now that we have a window we can create a context for OpenGL and set a few callback functions
    glfwMakeContextCurrent(window);

    /// This is called each time the window is resized. We make sure the viewport is following
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow *window, int width, int height){
        glViewport(0, 0, width, height);
    });

    /// Very simple input processing so that hitting escape key closes the application
    glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode, int action, int mods){
        switch(key) {
            case GLFW_KEY_ESCAPE: {
                glfwSetWindowShouldClose(window);
            } break;
            default:
                ;
        }
    });

    /// Now that the basis of our window is set we can initialize glew and enable a few useful callbacks and settings
    glewExperimental = GL_TRUE;
    /// Glew will reply with an enum value that will tell us more about issue it make encounter when initialized
    GLenum result = glewInit();
    if (result != GLEW_OK) {
        std::cerr << "[ GLEW Error ] : Glew failed to initialize with error ( " << glewGetErrorString(result) << " ).\nExiting ..." << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    /// Since we are not in production but in development we will need these outputs
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback([](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam){
#if type == GL_DEBUG_TYPE_ERROR
        std::cerr
#else
        std::cout
#endif
        << "[ OpenGL Callback ]\n" << (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "") << " type = 0x" << type << ", severity = 0x" << severity << "\nmessage = " << message << std::endl;
    }, 0);

    /// We don't want the window to refresh too often as it is empty for now. Let's vsync
    glfwSwapInterval(1);

    /// We can now set a nice blue as our background for our window. This can be set once so no need to set it for each loop
    glClearColor(0.2, 0.5, 0.8, 1.0);

    /// We can now begin the main loop
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /// We are about to exit the application so let's clean a bit
    glfwDestroyWindow(window);
    glfwTerminate();
    return EXIT_SUCCESS;
}
