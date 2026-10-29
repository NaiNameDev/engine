#include <engine/engine.hpp>

Engine::Engine::Engine(unsigned int width, unsigned int height, std::string app_name)
	: main_window(width, height, app_name), early_exit(false) {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW\n";
		exit(1);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	main_window.create_window();
	main_window.make_current();
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "ERR: failed to initialize GLAD\n";
		exit(1);
	}
	
	glfwSetWindowSize(main_window.glfw_window, main_window.width, main_window.height);
	
	last = glfwGetTime();
}

Engine::Engine::~Engine() {
	glfwTerminate();
}

void Engine::Engine::run() {
	ready_signal.emit();
	while(!main_window.should_close()) {
		current = (float)glfwGetTime();
		delta = current - last;
		last = current;

		main_window.clear();
		
		process_signal.emit(delta);

		main_window.swap_buffers();
		
		if (early_exit) break;
	}
	quit_signal.emit();
}

void Engine::Engine::quit() {
	early_exit = true;
}

void Engine::Engine::print_fps_info() {
	if (delta > 0.001f) {
		std::cout << "FPS: " << 1.0f / delta << ", DELTA: " << delta << "\n";
	}
}
