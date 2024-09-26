#include <iostream>

void IncreasingBubbleSort(int* A, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = size - 1; j >= i + 1;  --j) {
			if (A[j] < A[j - 1]) {
				std::swap(A[j], A[j - 1]);
			}
		}
	}
}

void DecreasingBubbleSort(int* A, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = size - 1; j >= i + 1; --j) {
			if (A[j] > A[j - 1]) {
				std::swap(A[j], A[j - 1]);
			}
		}
	}
}

int main() {
	int A[]{31, 41, 59, 26, 41, 58};
	const int n = sizeof(A) / sizeof(int);
	
	std::cout << "Original Array:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	IncreasingBubbleSort(A, n);

	std::cout << "Sorting in Ascending Order:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	DecreasingBubbleSort(A, n);

	std::cout << "Sorting in Descending Order:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}