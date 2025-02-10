#include <iostream>
using namespace std;
//Binomial coefficients
int com(int,int);
int mem[1000][1000];
int main() { 
	int n;
	cin >> n;
	cout << "(x+y)^" << n << " = ";
	for (int i = 0,c; i <= n; i++) {
		c = com(i, n);
		if (n - i == 0) cout << c << "y^" << i;
		else if (i == 0)cout << c << "x^" << n - i;
		else cout << c << "x^" << n - i << "y^" << i ;
		if (i != n) cout << "+";
	}
	return 0;
}
int com(int r , int n) {
	if (r == 0 || r == n) return 1;
	if (r == 1 || r == n - 1) return n;
	if (r == 2) return n * (n - 1) / 2;
	if (mem[r][n] != 0) return mem[r][n];
	mem[r][n] = com(r, n - 1) + com(r - 1, n - 1);
	return mem[r][n];
}