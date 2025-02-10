#include <iostream>
using namespace std;
const int infinity = -1000;
int* FindMaxCrossingSubarray(int*, int, int, int);
int* FindMaxSubarray(int*, int, int);
int main() {
	int n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	int* output = FindMaxSubarray(A, 0, n - 1);
	cout << "Max subarray starts at " << *output << " and ends in " << *(output + 1) << " and the max sum is " << *(output + 2) << endl;
	return 0;
}
int* FindMaxCrossingSubarray(int* A, int low, int mid, int high) {
	int left_sum = infinity;
	int sum = 0;
	int max_left, max_right;
	for (int i = mid; i >= low; i--) {
		sum += A[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = infinity;
	sum = 0;
	for (int j = mid + 1; j <= high; j++) {
		sum += A[j];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}
	int* output = new int[3];
	output[0] = max_left;
	output[1] = max_right;
	output[2] = left_sum + right_sum;
	return output;
}
int* FindMaxSubarray(int* A, int low, int high) {
	if (low == high) {
		int* output = new int[3];
		output[0] = low;
		output[1] = high;
		output[2] = A[low];
		return output; // base case : only one element
	}
	int mid = floor((low + high) / 2);
	int* leftArray = new int[3];
	int* rightArray = new int[3];
	int* crossArray = new int[3];
	leftArray = FindMaxSubarray(A, low, mid);
	rightArray = FindMaxSubarray(A, mid + 1, high);
	crossArray = FindMaxCrossingSubarray(A, low, mid, high);
	if (leftArray[2] >= rightArray[2] && leftArray[2] >= crossArray[2]) return leftArray;
	else if (rightArray[2] >= leftArray[2] && rightArray[2] >= crossArray[2]) return rightArray;
	return crossArray;
}