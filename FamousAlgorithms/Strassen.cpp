#include <iostream>
using namespace std;

void Strassen(int**, int**, int**, int, int, int, int, int);
void sum(int**, int**, int**, int, int, int, int, int, int, int);
void subtract(int**, int**, int**, int, int, int, int, int, int, int);

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
	Strassen(C, A, B, n, 0, 0, 0, 0);
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cout << C[i][j] << " ";
		
		cout << endl;
	}
	return 0;
}


void Strassen(int** C, int** A, int** B, int n, int rowA, int colA, int rowB, int colB)
{
	if (n == 1) {
		C[0][0] = A[rowA][colA] * B[rowB][colB];
		return;
	}
	int** S1 = new int* [n / 2];
	int** S2 = new int* [n / 2];
	int** S3 = new int* [n / 2];
	int** S4 = new int* [n / 2];
	int** S5 = new int* [n / 2];
	int** S6 = new int* [n / 2];
	int** S7 = new int* [n / 2];
	int** S8 = new int* [n / 2];
	int** S9 = new int* [n / 2];
	int** S10 = new int* [n / 2];

	int** P1 = new int* [n / 2];
	int** P2 = new int* [n / 2];
	int** P3 = new int* [n / 2];
	int** P4 = new int* [n / 2];
	int** P5 = new int* [n / 2];
	int** P6 = new int* [n / 2];
	int** P7 = new int* [n / 2];

	for (int i = 0; i < n; i++) {
		S1[i] = new int[n / 2];
		S2[i] = new int[n / 2];
		S3[i] = new int[n / 2];
		S4[i] = new int[n / 2];
		S5[i] = new int[n / 2];
		S6[i] = new int[n / 2];
		S7[i] = new int[n / 2];
		S8[i] = new int[n / 2];
		S9[i] = new int[n / 2];
		S10[i] = new int[n / 2];

		P1[i] = new int[n / 2];
		P2[i] = new int[n / 2];
		P3[i] = new int[n / 2];
		P4[i] = new int[n / 2];
		P5[i] = new int[n / 2];
		P6[i] = new int[n / 2];
		P7[i] = new int[n / 2];
	}

	int newSize = n / 2;

	subtract(S1, B, B, 0, 0, rowB, colB + newSize, rowB + newSize, colB + newSize, newSize);
	sum(S2, A, A, 0, 0, rowA, colA, rowA, colA + newSize, newSize);
	sum(S3, A, A, 0, 0, rowA + newSize, colA, rowA + newSize, colA + newSize, newSize);
	subtract(S4, B, B, 0, 0, rowB + newSize, colB, rowB, colB, newSize);
	sum(S5, A, A, 0, 0, rowA, colA, rowA + newSize, colA + newSize, newSize);
	sum(S6, B, B, 0, 0, rowB, colB, rowB + newSize, colB + newSize, newSize);
	subtract(S7, A, A, 0, 0, rowA, colA + newSize, rowA + newSize, colA + newSize, newSize);
	sum(S8, B, B, 0, 0, rowB + newSize, colB, rowB + newSize, colB + newSize, newSize);
	subtract(S9, A, A, 0, 0, rowA, colA, rowA + newSize, colA, newSize);
	sum(S10, B, B, 0, 0, rowB, colB, rowB, colB + newSize, newSize);

	Strassen(P1, A, S1, newSize, rowA, colA, 0, 0);
	Strassen(P2, S2, B, newSize, 0, 0, rowB + newSize, colB + newSize);
	Strassen(P3, S3, B, newSize, 0, 0, rowB, colB);
	Strassen(P4, A, S4, newSize, rowA + newSize, colA + newSize, 0, 0);
	Strassen(P5, S5, S6, newSize, 0, 0, 0, 0);
	Strassen(P6, S7, S8, newSize, 0, 0, 0, 0);
	Strassen(P7, S9, S10, newSize, 0, 0, 0, 0);

	sum(C, P5, P4, 0, 0, 0, 0, 0, 0, newSize);
	sum(C, C, P6, 0, 0, 0, 0, 0, 0, newSize);
	subtract(C, C, P2, 0, 0, 0, 0, 0, 0, newSize);

	sum(C, P1, P2, 0, newSize, 0, 0, 0, 0, newSize);

	sum(C, P3, P4, newSize, 0, 0, 0, 0, 0, newSize);

	sum(C, P5, P1, newSize, newSize, 0, 0, 0, 0, newSize);
	subtract(C, C, P3, newSize, newSize, newSize, newSize, 0, 0, newSize);
	subtract(C, C, P7, newSize, newSize, newSize, newSize, 0, 0, newSize);

}

void sum(int** S, int** A, int** B, int rowS, int colS, int rowA, int colA, int rowB, int colB, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			S[rowS + i][colS + j] = A[rowA + i][colA + j] + B[rowB + i][colB + j];
		}
	}
}

void subtract(int** S, int** A, int** B, int rowS, int colS, int rowA, int colA, int rowB, int colB, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			S[rowS + i][colS + j] = A[rowA + i][colA + j] - B[rowB + i][colB + j];
		}
	}
}
