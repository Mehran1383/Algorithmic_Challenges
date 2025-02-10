#include <iostream>
using namespace std;
//حل معادله درجه دوم
int main() {
	float  a, b, c, t;
	cin >> a >> b >> c;
	if (a == 0) {
		cout << "x = " << - 1 * c / b;
		return 0;
	}
	t = b * b - 4 * a * c;
	if (t >= 0) {
		t = sqrt(t);
		cout << "x1 = " << (-1 * b + t) / 2 * a << endl;
		cout << "x2 = " << (-1 * b - t) / 2 * a << endl;
		return 0;
	}
	t = abs(t);
	t = sqrt(t);
	cout << "x1 = " << -1 * b / 2 << " + " << t / 2 << "i" << endl;
	cout << "x2 = " << -1 * b / 2 << " - " << t / 2 << "i" << endl;
	return 0;
}