#include <iostream>
#include <queue>
#include <vector>

int main() {
	int A[]{15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};
	int size = sizeof(A) / sizeof(int);

	std::cout << "Original Array:\n";
	for (int i = 0; i < size; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Decreasing Priority Queue:\n";
	std::priority_queue<int> IncreasingPQ = {A, A+size};
	while (!IncreasingPQ.empty()) {
		std::cout << IncreasingPQ.top() << " ";
		IncreasingPQ.pop();
	}
	std::cout << std::endl;

	for (int i = 0; i < size; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Increasing Priority Queue:\n";
	std::priority_queue<int, std::vector<int>, std::greater<int>> DecreasingPQ = {A, A+size};
	while (!DecreasingPQ.empty()) {
		std::cout << DecreasingPQ.top() << " ";
		DecreasingPQ.pop();
	}
	std::cout << std::endl;

	return 0;
}