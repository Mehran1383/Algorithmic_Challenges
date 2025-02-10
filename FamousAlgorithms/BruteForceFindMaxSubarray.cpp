#include <iostream>
using namespace std;
int main() {
	int n, low, high, sum, MaxSum = -1000;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += A[j];
			if (sum > MaxSum) {
				MaxSum = sum;
				low = i;
				high = j;
			}
		}
	}
	cout << low << " " << high << " " << MaxSum << endl;
	return 0;
}