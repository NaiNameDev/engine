#pragma once

#include <glm/glm.hpp>

#include <engine/node.hpp>

namespace Engine::UI {

	class UIElement : public Node {
	public:
		glm::vec2 position;
		glm::vec2 rotation;
	
		glm::vec2 left_down;
		glm::vec2 right_up;

		UIElement(std::string nname);
		UIElement();
	};
};
