#include <iostream>

struct Node {
	int data;
	Node* next = nullptr;
	Node* prev = nullptr;
};

Node* Search(Node* head, int value) {
	Node* curr = head;
	while (curr != nullptr && curr->data != value) {
		curr = curr->next;
	}
	return curr;
}

void Insert(Node* node, Node* newNode) {
	newNode->prev = node->prev;
	newNode->next = node;
	if (node != nullptr) {
		node->prev = newNode;
	}
}

void Delete(Node* nodeToDelete) {
	nodeToDelete->next->prev = nodeToDelete->prev;
	nodeToDelete->prev->next = nodeToDelete->next;
}

int main() {
	Node *n1 = new Node;
	Node *n2 = new Node;
	Node *n3 = new Node;
	Node *n4 = new Node;
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;

	Insert(n4, n3);
	Insert(n3, n2);
	Insert(n2, n1);
	
	std::cout << n1->data << "->" << n1->next->data << "->" << n4->prev->data << "->" << n4->data << "->" << "NULL" << std::endl;

	Delete(n3);

	std::cout << n1->data << "->" << n1->next->data << "->" << n4->prev->data << "->" << n4->data << "->" << "NULL" << std::endl;

	delete n1;
	delete n2;
	delete n3;
	delete n4;

	return 0;
}