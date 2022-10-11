#include <chrono>
#include <sys/time.h>
#include <ctime>
#include <thread>
#include <cmath>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

using namespace std;

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
    // Boilerplate starting glfw
    glfwInit();

    // Boilerplate setting basic glfw window options
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // core profile is the more low level one

    // Creating a window with glfw
    GLFWwindow *window = glfwCreateWindow(800, 600, "FooBar", NULL, NULL);
    // If window was not successfully created stop glfw
    if (window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        return -1;
    }

    // Make C++ focus on the previously made window as its context
    glfwMakeContextCurrent(window);

    // Try to start GLAD to handle function pointers for OpenGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    // Instead of setting the size of the window itself, we set the size of the area in the window that should be rendered
    glViewport(0, 0, 800, 600);

    // Tell glfw to use our framebuffer_size_callback function to resize the render area to fit the window size whenever
    // the user resizes the window
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // We can create many more different callback functions between setting up the window and before the render loop starts.
    // For example, we can make a callback function to process joystick inputs, error messages, keypresses, etc.

    // Sets the color the screen will be set to when glClear(GL_COLOR_BUFFER_BIT); is called
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    // The render loop will prevent the window from immediately closing, this is where you can handle user input or render
    // more objects.

    // Repeat the render loop until the window is asked to close
    while (!glfwWindowShouldClose(window))
    {
        // Do stuff

        // Check the user's inputs and perform actions dependent on them
        processInput(window);

        // Re-renders the screen with the updated pixel values (i.e. the next frame)
        glfwSwapBuffers(window);
        // Windowing applications apply a double buffer to circumvent the flickering issue single buffers can cause
        // Instead swapping between buffers instead of modifying the currently in use buffer

        // Checks all the callback functions
        glfwPollEvents();
    }

    // Similar to how in python we like to f.close() after we're done using files, here we close glfw to clean up all the
    // resources glfw was using
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    // If, while the last glfwPollEvents(); was called, the user was pressing '0', close the window
    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

    // If the user is pressing '1' while the glfwPollEvents(); method is being called, clear the screen
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}