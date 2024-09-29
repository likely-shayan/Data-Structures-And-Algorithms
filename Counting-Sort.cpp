#include <iostream>

void IncreasingCountingSort(int* A, int size) {
	int max = 0;
	for (int i = 0; i < size; ++i) {
		max = std::max(max, A[i]);
	}
	int* Book = new int[max+1];
	for (int i = 0; i <= max; ++i) {
		Book[i] = 0;
	}
	for (int i = 0; i < size; ++i) {
		Book[A[i]]++;
	}
	int j = 0;
	for (int i = 0; i <= max; ++i) {
		while (Book[i] > 0) {
			A[j] = i;
			++j;
			--Book[i];
		}
	}
	delete [] Book;
}

void DecreasingCountingSort(int* A, int size) {
	int max = 0;
	for (int i = 0; i < size; ++i) {
		max = std::max(max, A[i]);
	}
	int* Book = new int[max+1];
	for (int i = 0; i <= max; ++i) {
		Book[i] = 0;
	}
	for (int i = 0; i < size; ++i) {
		Book[A[i]]++;
	}
	int j = 0;
	for (int i = max; i >= 0; --i) {
		while (Book[i] > 0) {
			A[j] = i;
			++j;
			--Book[i];
		}
	}
	delete [] Book;
}

int main() {
	int A[]{8, 6, 2, 7, 2, 6, 4, 7, 4, 2, 9, 7, 6, 0, 1};
	int size = sizeof(A) / sizeof(int);

	std::cout << "Original Array:\n";
	for (int i = 0; i < size; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	IncreasingCountingSort(A, size);

	std::cout << "Sorting In Increasing Order:\n";
	for (int i = 0; i < size; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	DecreasingCountingSort(A, size);

	std::cout << "Sorting In Decreasing Order:\n";
	for (int i = 0; i < size; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}