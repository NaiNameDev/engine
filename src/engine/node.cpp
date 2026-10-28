#include <engine/node.hpp>

Node::Node(std::string nname) : name(nname) {}
Node::~Node() {
	if (!(parent == this || parent == NULL)) {
		for (int i = 0; i < parent->childs.size(); i++) {
			if (parent->childs[i] == this) parent->childs.erase(parent->childs.begin() + i);
		}
	}
}

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
void Node::apply_to_tree(void(func)(Node*)) {
	func(this);
	for (auto ch : childs) {
		ch->apply_to_tree(func);
	}
}
