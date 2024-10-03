#include <iostream>
#include <queue>

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val) : data{val} {
		left = nullptr;
		right = nullptr;
	}
};

void RecursivePrintTree(Node* root) {
	if (root != nullptr) {
		std::cout << root->data << " ";
		RecursivePrintTree(root->left);
		RecursivePrintTree(root->right);
	}
}

void IterativePrintTree(Node* root) {
	if (root == nullptr) {
		return;
	}
	std::queue<Node*> Q;
	Q.push(root);
	while (!Q.empty()) {
		Node* curr = Q.front();
		Q.pop();
		std::cout << curr->data << " ";
		if (curr->left != nullptr) {
			Q.push(curr->left);
		}
		if (curr->right != nullptr) {
			Q.push(curr->right);
		}
	}
}

int main() {
	Node* n1 = new Node(7);
	n1->left = new Node(6);
	n1->right = new Node(5);
	n1->left->left = new Node(4);
	n1->left->right = new Node(3);
	n1->right->left = new Node(2);
	n1->right->right = new Node(1);

	std::cout << "\t\t\t" << n1->data << "\n\n";
	std::cout << "\t" << n1->left->data << "\t\t\t\t" << n1->right->data << "\n\n";
	std::cout << n1->left->left->data << "\t\t" << n1->left->right->data << "\t\t" << n1->right->left->data << "\t\t" << n1->right->right->data << "\n";
	
	std::cout << std::endl;
	RecursivePrintTree(n1);
	std::cout << std::endl;

	IterativePrintTree(n1);
	std::cout << std::endl;
	return 0;
}