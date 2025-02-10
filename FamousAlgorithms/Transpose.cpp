#include <iostream>
using namespace std;
int main() {
	int n, temp;
	cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) a[i] = new int[n];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}