#include <iostream>

int LinearSearch(int* A, int size, int value) {
	for (int i = 0; i < size; ++i) {
		if (A[i] == value) {
			return i;
		}
	}
	return -1;
}

int main() {
	int A[]{31, 41, 59, 26, 41, 58};
	const int n = sizeof(A) / sizeof(int);

	std::cout << LinearSearch(A, n, 26) << std::endl;

	return 0;
}