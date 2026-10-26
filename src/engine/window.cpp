#include <engine/window.hpp>

Window::Window(unsigned int nwidth, unsigned int nheight, std::string nname) {
	width = nwidth; height = nheight; name = nname;
}

void Window::create_window() {
	glfw_window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
	
	if (glfw_window == NULL) {
		glfwTerminate();
		std::cerr << "ERR: cant create window \"" << name << "\"\n";
		exit(-1);
	}
	
	window_owner_table[glfw_window] = this;
	glfwSetFramebufferSizeCallback(glfw_window,
		[](GLFWwindow* win, int w, int h) {
			window_owner_table[win]->width = w;
			window_owner_table[win]->height = h;
			
			window_owner_table[win]->resize_event.emit(w, h);

			glViewport(0, 0, w, h);
		}
	);
}

void Window::destroy_window() {
	glfwDestroyWindow(glfw_window);
}

Window::~Window() {
	destroy_window();
}

void Window::make_current() {
	glfwMakeContextCurrent(glfw_window);
}

void Window::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Window::swap_buffers() {
	glfwSwapBuffers(glfw_window);
	glfwPollEvents();
}
bool Window::should_close() {
	return glfwWindowShouldClose(glfw_window);
}
bool Window::is_action_pressed(unsigned int action) {
	return glfwGetKey(glfw_window, action) == GLFW_PRESS;
}
bool Window::is_action_just_pressed(unsigned int action) {
	if (key_map[action] == false && (glfwGetKey(glfw_window, action) == GLFW_PRESS)) {
		key_map[action] = true;
		return true;
	}
	if (glfwGetKey(glfw_window, action) == GLFW_RELEASE && key_map[action] == true) key_map[action] = false;
	return false;
}
