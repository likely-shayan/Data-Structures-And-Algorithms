#include <iostream>

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	TreeNode(int val) : data{val} {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};

class BinarySearchTree {
public:
	TreeNode* root = nullptr;

	BinarySearchTree() = default;

	// Returns the node containing the smallest value in the tree
	TreeNode* Minimum() {
		TreeNode* curr = root;
		while (curr->left != nullptr) {
			curr = curr->left;
		}
		return curr;
	}

	// Returns the node containing the largest value in the tree after curr
	TreeNode* Minimum(TreeNode* curr) {
		while (curr->left != nullptr) {
			curr = curr->left;
		}
		return curr;
	}

	// Returns the node containing the largest value in the tree
	TreeNode* Maximum() {
		TreeNode* curr = root;
		while (curr->right != nullptr) {
			curr = curr->right;
		}
		return curr;
	}

	// Returns the node containing the largest value in the tree after curr
	TreeNode* Maximum(TreeNode* curr) {
		while (curr->right != nullptr) {
			curr = curr->right;
		}
		return curr;
	}

	// Returns the first node containing value, otherwise return nullptr
	TreeNode* Search(int value) {
		TreeNode* temp = root;
		while (temp != nullptr && temp->data != value) {
			if (value < temp->data) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return temp;
	}

	// Insert newNode into the tree
	void Insert(TreeNode* newNode) {
		TreeNode* temp = nullptr;
		TreeNode* curr = root;
		while (curr != nullptr) {
			temp = curr;
			if (newNode->data < curr->data) {
				curr = curr->left;
			}
			else {
				curr = curr->right;
			}
		}
		newNode->parent = temp;
		if (temp == nullptr) {
			curr = newNode;
		}
		else if (newNode->data < temp->data) {
			temp->left = newNode;
		}
		else {
			temp->right = newNode;
		}
	}

	// Construct a node with given value and inserts into tree
	void Insert(int value) {
		TreeNode* newNode = new TreeNode(value);
		Insert(newNode);
	}

	// Deletes the given node
	void Delete(TreeNode* node) {
		if (node->left == nullptr) {
			Transplant(root, node, node->right);
		}
		else if (node->right == nullptr) {
			Transplant(root, node, node->left);
		}
		else {
			TreeNode* temp = Minimum(node->right);
			if (temp->parent != node) {
				Transplant(root, temp, temp->right);
				temp->right = node->right;
				temp->right->parent = node;
			}
			Transplant(root, node, temp);
			temp->left = node->left;
			node->left->parent = node;
		}
		delete node;
	}

	// Deletes the first node containing the given value
	void Delete(int value) {
		TreeNode* node = Search(value);
		Delete(node);
	}

	// Returns the node containing the value that is just greater than the value in given node
	TreeNode* Successor(TreeNode* node) {
		if (node->right != nullptr) {
			return Minimum(node->right);
		}
		TreeNode* parent = node->parent;
		while (parent != nullptr && node == parent->right) {
			node = parent;
			parent = parent->parent;
		}
		return parent;
	}

	// Returns the node containing the value that is just smaller than the value in given node
	TreeNode* Predecessor(TreeNode* node) {
		if (node->left != nullptr) {
			return Maximum(node->left);
		}
		TreeNode* parent = node->parent;
		while (parent != nullptr && node == parent->left) {
			node = parent;
			parent = parent->parent;
		}
		return parent;
	}

	// Printing the tree by walking in order from the given node on the given output-stream
	std::ostream& InOrderWalk(TreeNode* curr, std::ostream& in) {
		if (curr != nullptr) {
			InOrderWalk(curr->left, in);
			in << curr->data << " ";
			InOrderWalk(curr->right, in);
		}
		return in;
	}

	// Printing the tree by walking in order from root on the given output-stream
	std::ostream& InOrderWalk(std::ostream& in) {
		if (root != nullptr) {
			InOrderWalk(root->left, in);
			in << root->data << " ";
			InOrderWalk(root->right, in);
		}
		return in;
	}

	// Printing the tree by walking pre order from the given node on the given output-stream
	std::ostream& PreOrderWalk(TreeNode* curr, std::ostream& in) {
		if (curr != nullptr) {
			in << curr->data << " ";
			PreOrderWalk(curr->left, in);
			PreOrderWalk(curr->right, in);
		}
		return in;
	}

	// Printing the tree by walking pre order from root on the given output-stream
	std::ostream& PreOrderWalk(std::ostream& in) {
		if (root != nullptr) {
			in << root->data << " ";
			PreOrderWalk(root->left, in);
			PreOrderWalk(root->right, in);
		}
		return in;
	}

	// Printing the tree by walking post order from the given node on the given output-stream
	std::ostream& PostOrderWalk(TreeNode* curr, std::ostream& in) {
		if (curr != nullptr) {
			PostOrderWalk(curr->left, in);
			PostOrderWalk(curr->right, in);
			std::cout << curr->data << " ";
		}
		return in;
	}

	// Printing the tree by walking post order from root on the given output-stream
	std::ostream& PostOrderWalk(std::ostream& in) {
		if (root != nullptr) {
			PostOrderWalk(root->left, in);
			PostOrderWalk(root->right, in);
			std::cout << root->data << " ";
		}
		return in;
	}

	~BinarySearchTree() {
		DeleteTree(root);
	}

private:
	// Joins the subtree u and subtreee v
	void Transplant(TreeNode* root, TreeNode* u, TreeNode* v) {
		if (u->parent == nullptr) {
			root = v;
		}
		else if (u == u->parent->left) {
			u->parent->left = v;
		}
		else {
			u->parent->right = v;
		}
		if (v != nullptr) {
			v->parent = u->parent;
		}
	}

	// Deletes the entire tree recursively by deleting nodes in post-order walking style
	void DeleteTree(TreeNode* root) {
		if (root != nullptr) {
			DeleteTree(root->left);
			DeleteTree(root->right);
			delete root;
		}
	}	

};

int main() {

	BinarySearchTree BST;

	TreeNode* root = new TreeNode(15);
	BST.root = root;

	BST.Insert(6);
	BST.Insert(18);
	BST.Insert(3);
	BST.Insert(7);
	BST.Insert(17);
	BST.Insert(20);
	BST.Insert(2);
	BST.Insert(4);
	BST.Insert(13);
	BST.Insert(9);

	BST.InOrderWalk(root, std::cout);
	std::cout << std::endl;

	BST.PreOrderWalk(root, std::cout);
	std::cout << std::endl;

	BST.PostOrderWalk(root, std::cout);
	std::cout << std::endl;

	std::cout << BST.Search(15)->data << std::endl;

	std::cout << BST.Minimum(root)->data << std::endl;
	std::cout << BST.Maximum(root)->data << std::endl;

	std::cout << BST.Successor(root->left->left)->data << std::endl;
	std::cout << BST.Predecessor(root->left->left)->data << std::endl;

	return 0;
}