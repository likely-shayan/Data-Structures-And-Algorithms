#include <iostream>

void IncreasingSelectionSort(int* A, int size) {
	for (int i = 0; i < size; ++i) {
		int minimum = i;
		for (int j = i; j < size; ++j) {
			if (A[j] < A[minimum]) {
				minimum = j;
			}
		}
		std::swap(A[i], A[minimum]);
	}
}

void DecreasingSelectionSort(int* A, int size) {
	for (int i = 0; i < size; ++i) {
		int maximum = i;
		for (int j = i; j < size; ++j) {
			if (A[j] > A[maximum]) {
				maximum = j;
			}
		}
		std::swap(A[i], A[maximum]);
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

	IncreasingSelectionSort(A, n);

	std::cout << "Sorting in Ascending Order:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	DecreasingSelectionSort(A, n);

	std::cout << "Sorting in Descending Order:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}