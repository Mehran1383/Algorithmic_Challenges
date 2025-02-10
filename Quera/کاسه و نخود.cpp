/*
* https://quera.org/problemset/197000
*/

#include <iostream>
using namespace std;
int main() {
	int n, x, y, t;
	bool a[3] = { 1,0,0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		x--;
		y--;
		t = a[x]; a[x] = a[y]; a[y] = t;
	}
	if (a[0]) cout << 1;
	else if (a[1]) cout << 2;
	else cout << 3;
	return 0;
}