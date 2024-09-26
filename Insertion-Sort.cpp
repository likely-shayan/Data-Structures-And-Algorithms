#include <iostream>

void IncreasingInsertionSort(int* A, int n) {
	for (int i = 0; i < n; ++i) {
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j+1] = A[j];
			--j;
		}
		A[j+1] = key;
	}
}

void DecreasingInsertionSort(int* A, int n) {
	for (int i = 0; i < n; ++i) {
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] < key) {
			A[j+1] = A[j];
			--j;
		}
		A[j+1] = key;
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

	IncreasingInsertionSort(A, n);

	std::cout << "Sorting In Ascending:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	DecreasingInsertionSort(A, n);

	std::cout << "Sorting In Descending:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}