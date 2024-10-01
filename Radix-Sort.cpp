#include <iostream>
#include <string>
#include <algorithm>

void IncreasingRadixSort(int* A, int size) {
	int digits = std::to_string(*std::max_element(A, A+size)).size();

	for (int i = digits; i >= 0; --i) {
		std::sort(A, A+size, [&i](const int& a, const int& b){return std::to_string(a)[i] < std::to_string(b)[i];});
	}
}

void DecreasingRadixSort(int* A, int size) {
	int digits = std::to_string(*std::max_element(A, A+size)).size();

	for (int i = digits; i >= 0; --i) {
		std::sort(A, A+size, [&i](const int& a, const int& b){return std::to_string(a)[i] > std::to_string(b)[i];});
	}
}

int main() {
	int A[]{17, 90, 80, 20, 24, 45, 75, 66};
	int size = sizeof(A) / sizeof(int);

	std::cout << "Original Array:\n";
	for (int i = 0; i < size; ++i) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	IncreasingRadixSort(A, size);

	std::cout << "Sorting in Increasing Order:\n";
	for (int i = 0; i < size; ++i){
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	DecreasingRadixSort(A, size);

	std::cout << "Sorting in Decreasing Order:\n";
	for (int i = 0; i < size; ++i){
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}