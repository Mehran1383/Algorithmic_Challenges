#include <iostream>
using namespace std;
const int infinity = -1000;
int main() {
	int maxSum = infinity;
	int low, high, sum = 0, current = 0, n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) {
		sum += A[i];
		if (sum > maxSum) {
			maxSum = sum;
			low = current;
			high = i;
		}
		if (sum < 0) {
			sum = 0;
			current = i + 1;
		}
	}
	cout << "The subarray starts from " << low << " and ends in " << high << " so the max sum is " << maxSum << endl;
	return 0;
}