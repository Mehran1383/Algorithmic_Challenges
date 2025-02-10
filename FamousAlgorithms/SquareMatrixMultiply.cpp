#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int** A = new int* [n];
	int** B = new int* [n];
	int** C = new int* [n];
	for (int i = 0; i < n; i++) A[i] = new int[n];
	for (int i = 0; i < n; i++) B[i] = new int[n];
	for (int i = 0; i < n; i++) C[i] = new int[n];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> A[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> B[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = 0;
			for (int k = 0; k < n; k++) temp += A[i][k] * B[k][j];
			C[i][j] = temp;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << C[i][j] << " ";
		cout << endl;
	}
	return 0;
}