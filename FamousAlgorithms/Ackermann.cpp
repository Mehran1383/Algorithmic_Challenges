#include <iostream>
using namespace std;
int Ackermann(int, int);
int mem[10000][10000];
int main() {
	int m, n;
	cin >> m >> n;
	cout << Ackermann(m, n);
	return 0;
}
int Ackermann(int m, int n) {
	if (m == 0) return n + 1;
	if (mem[m][n] != 0) return mem[m][n];
	if (m > 0 && n == 0) {
		mem[m][n] = Ackermann(m - 1, 1);
		return mem[m][n];
	}
	if (m > 0 && n > 0) {
		mem[m][n] = Ackermann(m - 1, Ackermann(m, n - 1));
		return mem[m][n];
	}
}