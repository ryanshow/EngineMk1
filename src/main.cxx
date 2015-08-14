#include <chrono>
#include <thread>
#include "format.h"
#include "GLFW/glfw3.h"
#include "config.h"
#include "glbinding/gl/gl.h"
#include "glbinding/Binding.h"
#include "physfs.h"

using namespace gl;

static void glfw_error_callback(const int error, const char *description);
static void glfw_key_callback(GLFWwindow *window, const int key, const int scancode, const int action, const int mods);
static void glfw_framebuffer_size_callback(GLFWwindow *window, const int width, const int height);

int main(int argc, char *argv[]) {
	/*
	* Initialize GLFW and create a window
	*/
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	GLFWwindow *window = glfwCreateWindow(
		640, 480,							// width/height
		fmt::format("EngineMk1 v{}.{}.{}",	// title 
			EngineMk1_VERSION_MAJOR, 
			EngineMk1_VERSION_MINOR, 
			EngineMk1_VERSION_PATCH
		).c_str(), 
		NULL,								// windowed mode
		NULL								// do not share context with another window
	);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetKeyCallback(window, glfw_key_callback);
    glfwSetFramebufferSizeCallback(window, glfw_framebuffer_size_callback);

	/*
	* Initialize glBinding to create the OpenGL context and make it the context for the window
	*/
	glbinding::Binding::initialize();
	glfwMakeContextCurrent(window);
    
    /*
    * Initialize PhysicsFS
    */
    PHYSFS_init(argv[0]);
    PHYSFS_setSaneConfig("ryanshow", "EngineMk1", "ZIP", 0, 1);

	/*
	* Main game loop
	*/
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
		//std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}

	/*
	* Tear down everything
	*/
	glfwDestroyWindow(window);
	glfwTerminate();
    PHYSFS_deinit();
    
	return 0;
}

static void glfw_error_callback(const int error, const char *description) {
	fmt::print(stderr, "GLFW ERROR: {}", description);
}

static void glfw_key_callback(GLFWwindow *window, const int key, const int scancode, const int action, const int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

static void glfw_framebuffer_size_callback(GLFWwindow *window, const int width, const int height) {
	glViewport(0, 0, width, height);
}