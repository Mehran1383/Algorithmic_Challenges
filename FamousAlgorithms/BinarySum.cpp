#include <iostream>
using namespace std;
int main() {
	int a, b, x, y, c = 0, ans = 0, t = 0;
	cin >> a >> b;
	while (a != 0 || b!= 0 || c!= 0) {
		x = a % 10;
		y = b % 10;
		if (x + y + c < 2) {
			ans += (x + y + c) * pow(10, t);
			c = 0;
		}
		else if (x + y + c == 2) c = 1;
		else {
			ans += pow(10, t);
			c = 1;
		}
		a = a / 10;
		b = b / 10;
		t++;
	}
	cout << ans;
	return 0;

}