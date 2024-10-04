#include <iostream>

struct SinglyNode {
	int data;
	SinglyNode* next;
	
	SinglyNode(int val) : data{val} {
		next = nullptr;
	}
};

struct DoublyNode {
	int data;
	DoublyNode* prev;
	DoublyNode* next;

	DoublyNode(int val) : data{val} {
		prev = nullptr;
		next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyNode* head = nullptr;

	SinglyLinkedList() = default;

	SinglyLinkedList(int* Elements, int size) {
		SinglyNode* curr = nullptr;
		SinglyNode* prev = nullptr;
		for (int i = 0; i < size; ++i) {
			curr = new SinglyNode(Elements[i]);
			if (head == nullptr) {
				head = curr;
			}
			else {
				prev->next = curr;
			}
			prev = curr;
		}
	}

	SinglyLinkedList(int* begin, int* end) {
		SinglyNode* curr = nullptr;
		SinglyNode* prev = nullptr;
		while (begin != end) {
			curr = new SinglyNode(*begin);
			if (head == nullptr) {
				head = curr;
			}
			else {
				prev->next = curr;
			}
			prev = curr;
			++begin;
		}
	}

	// Return the first node from head storing value as data
	SinglyNode* Search(int value) {
		SinglyNode* curr = head;
		while (curr != nullptr && curr->data != value) {
			curr = curr->next;
		}
		return curr;
	}

	// Insert newNode after the prev node
	void Insert(SinglyNode* prev, SinglyNode* newNode) {
		SinglyNode* temp = prev->next;
		prev->next = newNode;
		newNode->next = temp;
	}

	// Insert a new Node storing value newVal after the prev node
	void Insert(SinglyNode* prev, int newVal) {
		SinglyNode* newNode = new SinglyNode(newVal);
		Insert(prev, newNode);
	}

	// Insert a new Node storing value newVal after the first node storing gvien value
	void Insert(int value, int newVal) {
		SinglyNode* prev = Search(value);
		Insert(prev, newVal);
	}

	// Insert new node after the first node storing given value
	void Insert(int value, SinglyNode* newNode) {
		SinglyNode* prev = Search(value);
		Insert(prev, newNode);
	}

	// Remove the given node
	void Remove(SinglyNode* node) {
		SinglyNode* temp = head;
		if (node == head) {
			head = head->next;
			delete temp;
			return;
		}
		while (temp->next != node) {
			temp = temp->next;
		}
		temp->next = node->next;
		delete node;
	}

	// Remove the first node storing given value
	void Remove(int value) {
		SinglyNode* node = Search(value);
		Remove(node);
	}

	// Update the value of node to newVal
	void Update(SinglyNode* node, int newVal) {
		node->data = newVal;
	}

	// Update the value of first node storing value currVal to newVal
	void Update(int currVal, int newVal) {
		SinglyNode* node = Search(currVal);
		Update(node, newVal);
	}

	~SinglyLinkedList() {
		SinglyNode* curr = head;
		while (curr != nullptr) {
			SinglyNode* temp = curr;
			curr = curr->next;
			delete temp;
		}
	}

};

class DoublyLinkedList {
public:
	DoublyNode* head = nullptr;

	DoublyLinkedList() = default;

	DoublyLinkedList(int* Elements, int size) {
		DoublyNode* curr = nullptr;
		DoublyNode* prev = nullptr;
		for (int i = 0; i < size; ++i) {
			curr = new DoublyNode(Elements[i]);
			if (head == nullptr) {
				head = curr;
			}
			else {
				prev->next = curr;
				curr->prev = prev;
			}
			prev = curr;
		}
	}

	DoublyLinkedList(int* begin, int* end) {
		DoublyNode* curr = nullptr;
		DoublyNode* prev = nullptr;
		while (begin != end) {
			curr = new DoublyNode(*begin);
			if (head == nullptr) {
				head = curr;
			}
			else {
				prev->next = curr;
				curr->prev = prev;
			}
			prev = curr;
			++begin;
		}	
	}

	DoublyNode* Search(int value) {
		DoublyNode* curr = head;
		while (curr != nullptr && curr->data != value) {
			curr = curr->next;
		}
		return curr;
	}

	// Insert newNode after the given node
	void Insert(DoublyNode* node, DoublyNode* newNode) {
		DoublyNode* temp = node->next;
		if (temp != nullptr) {
			temp->prev = newNode;
		}
		node->next = newNode;
		newNode->next = temp;
		newNode->prev = node;
	}

	// Insert a new Node storing value newVal after the prev node
	void Insert(DoublyNode* node, int newVal) {
		DoublyNode* newNode = new DoublyNode(newVal);
		Insert(node, newNode);
	}

	// Insert a new Node storing value newVal after the first node storing gvien value
	void Insert(int value, int newVal) {
		DoublyNode* node = Search(value);
		Insert(node, newVal);
	}

	// Insert new node after the first node storing given value
	void Insert(int value, DoublyNode* newNode) {
		DoublyNode* node = Search(value);
		Insert(node, newNode);
	}

	// Remove the given node
	void Remove(DoublyNode* node) {
		if (node == head) {
			head = head->next;
			delete node;
			return;
		}
		if (node->next != nullptr) {
			node->next->prev = node->prev;
		}
		node->prev->next = node->next;
		delete node;
	}

	// Remove the first node storing given value
	void Remove(int value) {
		DoublyNode* node = Search(value);
		Remove(node);
	}

	// Update the value of node to newVal
	void Update(DoublyNode* node, int newVal) {
		node->data = newVal;
	}

	// Update the value of first node storing value currVal to newVal
	void Update(int currVal, int newVal) {
		DoublyNode* node = Search(currVal);
		Update(node, newVal);
	}

	~DoublyLinkedList() {
		DoublyNode* curr = head;
		while (curr != nullptr) {
			DoublyNode* temp = curr;
			curr = curr->next;
			delete temp;
		}
	}
};