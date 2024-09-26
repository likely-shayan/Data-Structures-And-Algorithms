#include <iostream>

int IterativeBinarySearch(int* A, int low, int high, int value) {
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (A[mid] == value) {
			return mid;
		}
		else if (A[mid] < value) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

int RecursiveBinarySearch(int* A, int low, int high, int value) {
	if (high < low) {
		return -1;
	}
	int mid = low + (high - low) / 2;
	if (A[mid] == value) {
		return mid;
	}
	else if (A[mid] < value) {
		return RecursiveBinarySearch(A, mid + 1, high, value);
	}
	else {
		return RecursiveBinarySearch(A, low, mid - 1, value);
	}
}

int main() {
	int A[]{26, 31, 41, 41, 58, 59};
	const int n = sizeof(A) / sizeof(int);

	std::cout << IterativeBinarySearch(A, 0, n-1, 41) << std::endl;
	std::cout << RecursiveBinarySearch(A, 0, n-1, 41) << std::endl;

	return 0;
}