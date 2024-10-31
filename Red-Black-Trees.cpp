#include <iostream>

enum Color { RED, BLACK };

struct TreeNode {
    int data;
    Color color;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode(int val) : data{val} {
    	left = nullptr;
    	right = nullptr;
    	parent = nullptr;
    }
};

class RedBlackTree {
public:
    TreeNode* root = nullptr;

    RedBlackTree() = default;

    void Insert(TreeNode* z) {
        TreeNode* y = nullptr;
        TreeNode* x = this->root;

        while (x != nullptr) {
            y = x;
            if (z->data < x->data) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }

        z->parent = y;
        if (y == nullptr) {
            this->root = z;
        }
        else if (z->data < y->data) {
            y->left = z;
        }
        else {
            y->right = z;
        }

        z->left = nullptr;
        z->right = nullptr;
        z->color = RED;

        RedBlackInsertFixUp(z);
    }

    void Insert(int value) {
        TreeNode* newNode = new TreeNode(value);
        Insert(newNode);
    }

	std::ostream& InOrderWalk(TreeNode* curr, std::ostream& in) {
		if (curr != nullptr) {
			InOrderWalk(curr->left, in);
			in << curr->data << " ";
			InOrderWalk(curr->right, in);
		}
		return in;
	}

	std::ostream& InOrderWalk(std::ostream& in) {
		if (root != nullptr) {
			InOrderWalk(root->left, in);
			in << root->data << " ";
			InOrderWalk(root->right, in);
		}
		return in;
	}

	std::ostream& PreOrderWalk(TreeNode* curr, std::ostream& in) {
		if (curr != nullptr) {
			in << curr->data << " ";
			PreOrderWalk(curr->left, in);
			PreOrderWalk(curr->right, in);
		}
		return in;
	}

	std::ostream& PreOrderWalk(std::ostream& in) {
		if (root != nullptr) {
			in << root->data << " ";
			PreOrderWalk(root->left, in);
			PreOrderWalk(root->right, in);
		}
		return in;
	}

	std::ostream& PostOrderWalk(TreeNode* curr, std::ostream& in) {
		if (curr != nullptr) {
			PostOrderWalk(curr->left, in);
			PostOrderWalk(curr->right, in);
			std::cout << curr->data << " ";
		}
		return in;
	}

	std::ostream& PostOrderWalk(std::ostream& in) {
		if (root != nullptr) {
			PostOrderWalk(root->left, in);
			PostOrderWalk(root->right, in);
			std::cout << root->data << " ";
		}
		return in;
	}

    ~RedBlackTree() {
    	DeleteTree(this->root);
    }

private:
    void LeftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void RightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        y->left = x->right;
        if (x->right != nullptr) {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (y->parent == nullptr) {
            this->root = x;
        }
        else if (y == y->parent->right) {
            y->parent->right = x;
        }
        else {
            y->parent->left = x;
        }
        x->right = y;
        y->parent = x;
    }

    void RedBlackInsertFixUp(TreeNode* z) {
        while (z->parent != nullptr && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                TreeNode* y = z->parent->parent->right;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        LeftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    RightRotate(z->parent->parent);
                }
            }
            else {
                TreeNode* y = z->parent->parent->left;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        RightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    LeftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void DeleteTree(TreeNode* x) {
    	if (x != nullptr) {
    		DeleteTree(x->left);
	    	DeleteTree(x->right);
	    	delete x;
    	}
    }
};

int main() {
	RedBlackTree T;
	T.Insert(41);
	T.Insert(38);
	T.Insert(31);
	T.Insert(12);
	T.Insert(19);
	T.Insert(8);

	T.PreOrderWalk(std::cout);
	std::cout << std::endl;

	T.PostOrderWalk(std::cout);
	std::cout << std::endl;

	T.InOrderWalk(std::cout);
	std::cout << std::endl;

	return 0;
}