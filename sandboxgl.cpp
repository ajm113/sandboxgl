#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>
#include "spdlog/spdlog.h"

class SandboxGL {
public:
    SandboxGL() : window(nullptr) {}

    bool init() {
        spdlog::info("starting sandboxgl");
        if (!glfwInit()) {
            spdlog::error("failed starting GLFW!");
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);


        window = glfwCreateWindow(600, 300, "Sandboxgl", nullptr, nullptr);
        if(!window) {
            spdlog::error("failed to create GLFW window");
            clearAll();
            return false;
        }

        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, this);
        glfwSetKeyCallback(window, key_callback);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        return true;
    }

    void run() {
        if (!window) {
            spdlog::critical("GLFW window not initialized! Did you run init()?");
            return;
        }

        while(!glfwWindowShouldClose(window)) {
            render();
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        clearAll();
    }
private:
    GLFWwindow* window;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
      if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
        return;
      }
    }

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
      glViewport(0, 0, width, height);
    }


    void render() {
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
    }

    void clearAll() {
        spdlog::info("shutdown");
        if(window) {
            glfwDestroyWindow(window);
        }

        glfwTerminate();
    }
};


int main() {
    SandboxGL app;

    if(!app.init()) {
        return 1;
    }

    app.run();

	return 0;	
}
