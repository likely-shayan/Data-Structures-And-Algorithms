#include <iostream>
#include <climits>

int MaxCrossingSubArray(int* A, int low, int mid, int high) {
	int LeftSum = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= low; --i) {
		sum += A[i];
		LeftSum = std::max(LeftSum, sum);
	}

	int RightSum = INT_MIN;
	sum = 0;
	for (int j = mid + 1; j <= high; ++j) {
		sum += A[j];
		RightSum = std::max(RightSum, sum);
	}
	return LeftSum + RightSum;
}

int MaximumSubArray(int* A, int low, int high) {
	if (high == low) {
		return A[low];
	}
	int mid = low + (high - low) / 2;
	int LeftSum = MaximumSubArray(A, low, mid);
	int RightSum = MaximumSubArray(A, mid + 1, high);
	int CrossSum = MaxCrossingSubArray(A, low, mid, high);
	if (LeftSum >= RightSum && LeftSum >= CrossSum) {
		return LeftSum;
	}
	else if (RightSum >= LeftSum && RightSum >= CrossSum) {
		return RightSum;
	}
	return CrossSum;
}

int main() {
	int A[]{1, -2, 3, -3, 2, -1};
	const int n = sizeof(A) / sizeof(int);

	std::cout << MaximumSubArray(A, 0, n-1) << std::endl;

	return 0;
}