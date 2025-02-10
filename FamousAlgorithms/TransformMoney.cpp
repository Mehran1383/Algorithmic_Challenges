#include <iostream>
using namespace std;
//خرد کردن پول
int main() {
	int n, c5, c2;
	cin >> n;
	c5 = n / 5;
	n = n % 5;
	c2 = n / 2;
	n = n % 2;
	cout << c5 << " * 5 + " << c2 << " * 2 + " << n << " * 1";
	return 0;
}
