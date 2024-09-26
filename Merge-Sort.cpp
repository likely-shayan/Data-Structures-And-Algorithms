#include <iostream>

void IncreasingMerge(int* A, int low, int mid, int high) {
	int n = mid - low + 1;
	int m = high - mid;
	int L[n];
	int R[m];
	for (int i = 0; i < n; ++i) {
		L[i] = A[low + i];
	}
	for (int j = 0; j < m; ++j) {
		R[j] = A[mid + 1 + j];
	}
	int i = 0, j = 0, k = low;
	while (i < n && j < m) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			++i;
		}
		else {
			A[k] = R[j];
			++j;
		}
		++k;
	}
	while (i < n) {
		A[k] = L[i];
		++i;
		++k;
	}
	while (j < m) {
		A[k] = R[j];
		++j;
		++k;
	}
}

void DecreasingMerge(int* A, int low, int mid, int high) {
	int n = mid - low + 1;
	int m = high - mid;
	int L[n];
	int R[m];
	for (int i = 0; i < n; ++i) {
		L[i] = A[low+i];
	}
	for (int j = 0; j < m; ++j) {
		R[j] = A[mid + 1 + j];
	}

	int i = 0, j = 0, k = low;
	while (i < n && j < m) {
		if (R[j] >= L[i]) {
			A[k] = R[j];
			++j;
		}
		else {
			A[k] = L[i];
			++i;
		}
		++k;
	}
	while (i < n) {
		A[k] = L[i];
		++i;
		++k;
	}
	while (j < m) {
		A[k] = R[j];
		++j;
		++k;
	}
}

void IncreasingMergeSort(int* A, int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		IncreasingMergeSort(A, low, mid);
		IncreasingMergeSort(A, mid+1, high);
		IncreasingMerge(A, low, mid, high);
	}
}

void DecreasingMergeSort(int* A, int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		DecreasingMergeSort(A, low, mid);
		DecreasingMergeSort(A, mid+1, high);
		DecreasingMerge(A, low, mid, high);
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

	std::cout << "Sorting In Ascending Order:\n";
	IncreasingMergeSort(A, 0, n-1);
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Sorting In Descending Order:\n";
	DecreasingMergeSort(A, 0, n-1);
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}