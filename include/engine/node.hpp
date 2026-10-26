class Node {
private:

public:
	std::string name;

	Node(std::string nnmae);

	Node* parrent;
	std::vector<Node*> childs;

	void add_child(Node* child);
	void print_tree_from_here(int depth);
};
