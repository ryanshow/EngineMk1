#include <chrono>
#include <thread>
#include "format.h"
#include "GLFW/glfw3.h"
#include "config.h"

static void glfw_error_callback(const int error, const char* description);
static void glfw_key_callback(GLFWwindow* window, const int key, const int scancode, const int action, const int mods);
static void glfw_framebuffer_size_callback(GLFWwindow* window, const int width, const int height);

int main(int argc, char *argv[]) {
	fmt::print("EngineMk1 Version {}.{}\n", EngineMk1_VERSION_MAJOR, EngineMk1_VERSION_MINOR);
	
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	GLFWwindow* window = glfwCreateWindow(640, 480, "EngineMk1", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, glfw_key_callback);
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
		//std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

static void glfw_error_callback(const int error, const char* description) {
	fmt::print(stderr, "GLFW ERROR: {}", description);
}

static void glfw_key_callback(GLFWwindow* window, const int key, const int scancode, const int action, const int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

static void glfw_framebuffer_size_callback(GLFWwindow* window, const int width, const int height) {
	glViewport(0, 0, width, height);
}