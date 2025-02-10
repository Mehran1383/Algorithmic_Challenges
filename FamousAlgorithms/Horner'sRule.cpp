#include <iostream>
using namespace std;
int main() {
	int n , x;
	cin >> n;
	int* poly = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		cin >> poly[i];
	}
	cin >> x;
	for (int i = 0; i < n; i++) {
		poly[i + 1] = x * poly[i] + poly[i + 1];
	}
	for (int i = 0; i < n ; i++) {
		if (n - 1 - i == 0) cout << poly[i];
		else cout << poly[i] << "x^" << n - i - 1;
		if (i != n - 1) cout << "+";
	}
	cout << endl << poly[n];
	return 0;
}