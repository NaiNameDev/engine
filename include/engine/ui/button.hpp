#pragma once

#include <engine/signal.hpp>
#include <engine/ui/uielement.hpp>

namespace Engine::UI {

	bool is_inside_rect(glm::vec2 point, glm::vec2 left_down, glm::vec2 right_up);

	class Button : public UIElement {
	public:
		Engine::Signal<> on_press;
	
		Button(std::string nname);
		Button();
	
		void draw();
	};

};
