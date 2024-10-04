#include <iostream>
#include <queue>

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) : data{val} {
		left = nullptr;
		right = nullptr;
	}
};

class BinaryTree {
public:
	TreeNode* root = nullptr;

	BinaryTree() = default;

	BinaryTree(int* Elements, int size) {
		if (size == 0) {
			return;
		}
		root = new TreeNode(Elements[0]);
		std::queue<TreeNode*> Q;
		Q.push(root);
		int i = 1;
		while (i < size) {
			TreeNode* curr = Q.front();
			Q.pop();
			if (i < size) {
				curr->left = new TreeNode(Elements[i]);
				++i;
				Q.push(curr->left);
			}
			if (i < size) {
				curr->right = new TreeNode(Elements[i]);
				++i;
				Q.push(curr->right);
			}
		}
	}

	~BinaryTree() {
		destroyTree(root);
	}

private:
	void destroyTree(TreeNode* node) {
		if (node != nullptr) {
			destroyTree(node->left);
			destroyTree(node->right);
			delete node;
		}
	}
};

void RecursivePrintTree(TreeNode* root) {
	if (root != nullptr) {
		std::cout << root->data << " ";
		RecursivePrintTree(root->left);
		RecursivePrintTree(root->right);
	}
}

void IterativePrintTree(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	std::queue<TreeNode*> Q;
	Q.push(root);
	while (!Q.empty()) {
		TreeNode* curr = Q.front();
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
	int A[]{1, 2, 3, 4, 5, 6, 7};
	int size = sizeof(A) / sizeof(int);

	BinaryTree T(A, size);

	IterativePrintTree(T.root);
	std::cout << std::endl;
	RecursivePrintTree(T.root);

	return 0;
}