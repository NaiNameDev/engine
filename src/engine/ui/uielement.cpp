#include <engine/ui/uielement.hpp>

Engine::UI::UIElement::UIElement(std::string nname) : Engine::Node(nname), scale(glm::vec2(1,1)) {}
Engine::UI::UIElement::UIElement() : Engine::Node("UIElement"), scale(glm::vec2(1,1)) {}
