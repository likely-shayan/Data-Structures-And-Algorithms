#include <iostream>

int IncreasingPartition(int* A, int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r-1; ++j) {
		if (A[j] <= x) {
			++i;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i+1], A[r]);
	return i+1;
}

int DecreasingPartition(int* A, int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r-1; ++j) {
		if (A[j] >= x) {
			++i;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i+1], A[r]);
	return i+1;
}

void IncreasingQuickSort(int* A, int p, int r) {
	if (p < r) {
		int q = IncreasingPartition(A, p, r);
		IncreasingQuickSort(A, p, q-1);
		IncreasingQuickSort(A, q, r);
	}
}

void DecreasingQuickSort(int* A, int p, int r) {
	if (p < r) {
		int q = DecreasingPartition(A, p, r);
		DecreasingQuickSort(A, p, q-1);
		DecreasingQuickSort(A, q, r);
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

	IncreasingQuickSort(A, 0, n-1);

	std::cout << "Sorting in Ascending Order:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	DecreasingQuickSort(A, 0, n-1);

	std::cout << "Sorting in Descending Order:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}