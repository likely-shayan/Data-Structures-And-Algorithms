#include <iostream>

int Parent(int i) {
	return i - 1 / 2;
}

int Left(int i) {
	return 2 * i + 1;
}

int Right(int i) {
	return 2 * i + 2;
}

void MaxHeapify(int* A, int size, int i) {
	int l = Left(i);
	int r = Right(i);
	int largest = i;
	if (l < size && A[l] > A[largest]) {
		largest = l;
	}
	if (r < size && A[r] > A[largest]) {
		largest = r;
	}
	if (largest != i) {
		std::swap(A[i], A[largest]);
		MaxHeapify(A, size, largest);
	}
}

void MinHeapify(int* A, int size, int i) {
	int l = Left(i);
	int r = Right(i);
	int smallest = i;
	if (l < size && A[l] < A[smallest]) {
		smallest = l;
	}
	if (r < size && A[r] < A[smallest]) {
		smallest = r;
	}
	if (smallest != i) {
		std::swap(A[i], A[smallest]);
		MaxHeapify(A, size, smallest);
	}
}

void BuildMaxHeap(int* A, int size) {
	for (int i = size/2 - 1; i >= 0; --i) {
		MaxHeapify(A, size, i);
	}
}

void BuildMinHeap(int* A, int size) {
	for (int i = size/2 - 1; i >= 0; --i) {
		MinHeapify(A, size, i);
	}
}

void IncreasingHeapSort(int* A, int size) {
	BuildMaxHeap(A, size);
	for (int i = size - 1; i > 0; --i) {
		std::swap(A[0], A[i]);
		MaxHeapify(A, i, 0);
	}
}

void DecreasingHeapSort(int* A, int size) {
	BuildMinHeap(A, size);
	for (int i = size - 1; i > 0; --i) {
		std::swap(A[0], A[i]);
		MinHeapify(A, i, 0);
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

	std::cout << "Sorting in Ascending Order:\n";
	IncreasingHeapSort(A, n);
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Sorting in Descending Order:\n";
	DecreasingHeapSort(A, n);
	for (int i = 0; i < n; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}