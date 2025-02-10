#include <iostream>
using namespace std;
#define Infinity 1000
int CountInversions(int*, int, int);
int MergeInversions(int*, int, int, int);
int main() {
	int n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	int p = 0, r = n - 1;
	cout << CountInversions(A, p, r);
	return 0;
}
int CountInversions(int* A, int p, int r) {
	int inversions = 0;
	if (p < r) {
		int q = (p + r) / 2;
		inversions += CountInversions(A, p, q);
		inversions += CountInversions(A, q + 1, r);
		inversions += MergeInversions(A, p, q, r);
	}
	return inversions;
}
int MergeInversions(int* A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int inversions = 0;
	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];
	for (int i = 0; i < n1; i++) L[i] = A[p + i];
	for (int j = 0; j < n2; j++) R[j] = A[q + j + 1];
	L[n1] = Infinity;
	R[n2] = Infinity;
	for (int k = p, i = 0, j = 0; k <= r; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			inversions += n1 - i;
			A[k] = R[j];
			j++;
		}
	}
	return inversions;
}