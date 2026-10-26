#include <iostream>

#include <engine/engine.hpp>
#include <engine/node.hpp>

Engine engine(1280, 720, "engine");

void mouse_event(double pos_x, double pos_y) {
	std::cout << "velocity x " << pos_x << ", velocity y " << pos_y << "\n";
}
void resize_event(int w, int h) {
	std::cout << "resize event: " << w << ", " << h << "\n";
}

void on_ready() {
	std::cout << "start!\n";

	engine.global_mouse_event.connect(mouse_event);
	engine.main_window.resize_event.connect(resize_event);

	Node t1("t1");
	Node t2("t2");
	Node t3("t3");
	Node t4("t4");
	Node t5("t5");
	t1.add_child(&t2);
	t1.add_child(&t3);
	t2.add_child(&t4);
	t2.add_child(&t5);
	t1.print_tree_from_here(0);
}
void process(float delta) {
	//engine.print_fps_info();
	if (engine.main_window.is_action_pressed(GLFW_KEY_Q)) engine.quit();
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
