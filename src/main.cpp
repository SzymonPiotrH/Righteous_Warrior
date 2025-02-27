#include <iostream>

#define GLFW_INCLUDE_VULKAN 
#include <GLFW/glfw3.h>

int32_t main(void) {
    glfwInit();
    std::print(std::cout, "Hello world!\n");

    return 0;
}
