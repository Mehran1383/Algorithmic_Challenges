#include <iostream>
using namespace std;
//Algorithm Max(A,n)
//A is an array of size n.
int main() {
	int n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int result = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i] > result) result = A[i];
	}
	cout << result;
	return 0;
}