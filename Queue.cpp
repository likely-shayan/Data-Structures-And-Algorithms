#include <iostream>
#include <queue>

int main() {
	std::queue<int> Queue;

	int A[]{17, 90, 80, 20, 24, 45, 75, 66};
	int size = sizeof(A) / sizeof(int);

	std::cout << "Original Array:\n";
	for (int i = 0; i < size; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < size; ++i) {
		Queue.push(A[i]);
	}

	std::cout << "Popping elements off the Queue:\n";
	std::cout << "Front Back\n";
	while (!Queue.empty()) {
		std::cout << Queue.front() << "    " << Queue.back() << "\n";
		Queue.pop();
	}

	return 0;
}