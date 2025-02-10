/*
https://quera.org/problemset/618
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int j = 0; j < 2 * n + 1; j++) {
		for (int i = 0; i < 2 * n + 1; i++) {
			if (i >= n - j && i <= n + j && j <= n) cout << "*";
			else if (i >= abs(n - j) && i <= 3 * n - j && j > n) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}


}