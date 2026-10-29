#include <iostream>

#include <engine/engine.hpp>
#include <engine/node.hpp>
#include <engine/ui/uielement.hpp>

Engine::Engine engine(1280, 720, "engine");

void mouse_event(double pos_x, double pos_y) {
	std::cout << "mouse pos update: " << pos_x << ", " << pos_y << "\n";
}
void key_press_event(int key, int action) {
	if (key == GLFW_KEY_Q && action == GLFW_PRESS) engine.quit();
	if (key == GLFW_KEY_T && action == GLFW_PRESS) std::cout << "T pressed\n";
}
void mouse_button_event(int button, int action) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) std::cout << "mouse pressed\n";
}
void resize_event(int w, int h) {
	std::cout << "resize event: " << w << ", " << h << "\n";
}

void on_ready() {
	std::cout << "start!\n";

	engine.main_window.mouse_move_event.connect(mouse_event);
	engine.main_window.mouse_button_event.connect(mouse_button_event);
	engine.main_window.key_press_event.connect(key_press_event);
	engine.main_window.resize_event.connect(resize_event);

	Engine::UI::UIElement t1;
	Engine::Node t2;
	Engine::Node t3;
	t1.add_child(&t2);
	t1.add_child(&t3);
	
	t1.print_tree_from_here(0);
}
void process(float delta) {
	//engine.print_fps_info();
}
void on_quit() {
	std::cout << "end!\n";
}

int main() {
	engine.ready_signal.connect(on_ready);
	engine.process_signal.connect(process);
	engine.quit_signal.connect(on_quit);
	
	engine.run();
}
