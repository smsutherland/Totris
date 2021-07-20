#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer/Renderer.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Tetris/Tetris.h"

int main(void) {

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1080, 720, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;
    
    std::cout << glGetString(GL_VERSION) << std::endl;

    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    Renderer renderer;
    renderer.setClearColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    Tetris game;

    int i = 0;
    double prevTime = 0.0;
    double currentTime = 1.0;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {

        if (i % 120 == 0) {
            currentTime = glfwGetTime();

            std::string title = "Framerate: " + std::to_string(120/(currentTime - prevTime));
            prevTime = currentTime;
            glfwSetWindowTitle(window, title.c_str());
        }


        /* Render here */
        renderer.clear();

        game.nextFrame(1.0f);
        i++;
        if (i == 120) {
            game.cycleTetramino();
            i = 0;
        }
        else if (i % 30 == 0)
            game.rotate();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        //float a = ImGui::GetIO().Framerate;

    }

    glfwTerminate();
    return 0;
}