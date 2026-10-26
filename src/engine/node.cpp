#include <engine/node.hpp>

Node::Node(std::string nname) : name(nname) {}

void Node::add_child(Node* child) {
	childs.push_back(child);
}
void Node::print_tree_from_here(int depth = 0) {
	for (int i = 0; i < depth; i++) std::cout << "  ";
	std::cout << name << "\n";

	for (auto ch : childs) {
		ch->print_tree_from_here(depth+1);
	}
}
