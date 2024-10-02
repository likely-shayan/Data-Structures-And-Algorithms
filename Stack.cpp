#include <iostream>
#include <stack>

int main() {
	std::stack<int> Stack;

	int A[]{17, 90, 80, 20, 24, 45, 75, 66};
	int size = sizeof(A) / sizeof(int);

	std::cout << "Original Array:\n";
	for (int i = 0; i < size; ++i) {
		std::cout << A[i] << " ";
	}
    std::cout << std::endl;

	for (int i = 0; i < size; ++i) {
		Stack.push(A[i]);
	}

	std::cout << "Popping elements off the Stack:\n";
	while (!Stack.empty()) {
		std::cout << Stack.top() << " ";
		Stack.pop();
	}

	return 0;
}