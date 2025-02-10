#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int p = pow(2, n);
	bool** table = new bool* [p];
	for (int i = 0; i < p; i++) {
		table[i] = new bool[n];
	}
	for (int j = 0 , k = p , c; j < n; j++) {
		k /= 2;
		c = k;
		bool check = 1;
		for (int i = 0; i < p; i++ , c--) {
			if (c == 0) {
				c = k;
				check = !check;
			}
			table[i][j] = check;
		}
	}
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < n; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}