#include <iostream>

int* BinaryAddition(int* A, int* B, int size) {
	int* C = new int[size+1];
	int k = 0;
	int carry = 0;
	for (int i = size-1; i >= 0; --i) {
		if (A[i] == 1 && B[i] == 1) {
			if (carry == 1) {
				C[k] = 1;
				carry = 1;
			}
			else {
				C[k] = 0;
				carry = 1;
			}
		}
		else if (A[i] == 0 && B[i] == 0) {
			if (carry == 1) {
				C[k] = 1;
				carry = 0;
			}
			else {
				C[k] = 0;
				carry = 0;
			}
		}
		else if (A[i] != B[i]) {
			if (carry == 1) {
				C[k] = 0;
				carry = 1;
			}
			else {
				C[k] = 1;
				carry = 0;
			}
		}
		++k;
	}
	if (carry == 1) {
		C[k] = 1;
	}
	return C;
}

int main() {
	int A[]{1, 0, 1, 1};
	int B[]{0, 1, 1, 1};
	const int n = sizeof(A) / sizeof(int);

	int* C = BinaryAddition(A, B, n);
	for (int i = n; i >= 0; --i) {
		std::cout << C[i] << " ";
	}
	delete [] C;

	return 0;
}