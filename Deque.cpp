#include <iostream>
#include <deque>

int main() {
	std::deque<int> Deque;

	int A[]{17, 90, 80, 20, 24, 45, 75, 66};
	int size = sizeof(A) / sizeof(int);

	std::cout << "Original Array:\n";
	for (int i = 0; i < size; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < size/2; ++i) {
		Deque.push_front(A[i]);
		Deque.push_back(A[size - i - 1]);
	}

	std::cout << "Popping elements off the Deque From Front and Back:\n";
	std::cout << "Front Back\n";
	while (!Deque.empty()) {
		std::cout << Deque.front() << "    " << Deque.back() << "\n";
		Deque.pop_front();
		Deque.pop_back();
	}

	return 0;
}