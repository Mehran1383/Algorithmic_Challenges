/*
https://quera.org/problemset/9773
*/
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; j++) {
		int i = 0;
		while (i < abs(n / 2 - j)) {
			cout << " ";
			i++;
		}
		int count = n - 2 * abs(n / 2 - j);
		int check = count;
		while (check) {
			cout << "*";
			check--;
		}
		int k = i;
		while (i < k + 2 * abs(n / 2 - j)) {
			cout << " ";
			i++;
		}
		check = count;
		while (check) {
			cout << "*";
			check--;
		}
		cout << endl;
	}
	return 0;
}