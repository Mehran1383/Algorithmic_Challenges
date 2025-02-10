#include <iostream>
using namespace std;
int** SquareMatrixMultiplyRecursive(int**, int**, int, int, int, int, int);
void SumMatrix(int**, int**, int**, int, int, int);
int main() {
	int n;
	cin >> n;
	int** A = new int* [n];
	int** B = new int* [n];
	int** C = new int* [n];
	for (int i = 0; i < n; i++) A[i] = new int[n];
	for (int i = 0; i < n; i++) B[i] = new int[n];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> A[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> B[i][j];
	for (int i = 0; i < n; i++) C[i] = new int[n];
	C = SquareMatrixMultiplyRecursive(A, B, n, 0, 0, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << C[i][j] << " ";
		cout << endl;
	}
	return 0;
}
int** SquareMatrixMultiplyRecursive(int** A, int** B, int n, int rowA, int colA, int rowB, int colB) {
	int** C = new int* [n];
	for (int i = 0; i < n; i++) C[i] = new int[n];
	if (n == 1) {
		C[0][0] = A[rowA][colA] * B[rowB][colB];
		return C;
	}
	int newSize = n / 2;
	SumMatrix(C, SquareMatrixMultiplyRecursive(A, B, newSize, rowA, colA, rowB, colB), SquareMatrixMultiplyRecursive(A, B, newSize, rowA, colA + newSize, rowB + newSize, colB), 0, 0, newSize);
	SumMatrix(C, SquareMatrixMultiplyRecursive(A, B, newSize, rowA, colA, rowB, colB + newSize), SquareMatrixMultiplyRecursive(A, B, newSize, rowA, colA + newSize, rowB + newSize, colB + newSize), 0, newSize, newSize);
	SumMatrix(C, SquareMatrixMultiplyRecursive(A, B, newSize, rowA + newSize, colA, rowB, colB), SquareMatrixMultiplyRecursive(A, B, newSize, rowA + newSize, colA + newSize, rowB + newSize, colB), newSize, 0, newSize);
	SumMatrix(C, SquareMatrixMultiplyRecursive(A, B, newSize, rowA + newSize, colA, rowB, colB + newSize), SquareMatrixMultiplyRecursive(A, B, newSize, rowA + newSize, colA + newSize, rowB + newSize, colB + newSize), newSize, newSize, newSize);
	return C;
}
void SumMatrix(int** C, int** A, int** B, int rowC, int colC, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i + rowC][j + colC] = A[i][j] + B[i][j];
		}
	}
}