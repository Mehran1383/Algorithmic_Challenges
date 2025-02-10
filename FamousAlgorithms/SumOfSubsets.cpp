#include <iostream>
using namespace std;
int binary(int);
int main() {
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int b, sum = 0, count = 0;
	for (int i = 0 , j = 0; i < 1024; i++) {
		sum = 0; j = 0;
		b = binary(i);
		while (b != 0) {
			if (b % 10 == 1) sum += a[j];
			b = b / 10;
		}
		if (sum % 2 == 0) count++;
	}
	cout << count;
	return 0;
}
int binary(int a) {
	int t = 0 , ans = 0 , r;
	while (a != 0) {
		r = a % 2;
		ans += r * pow(10, t);
		a = a / 2;
		t++;
	}
	return ans;
}