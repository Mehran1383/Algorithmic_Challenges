#include <iostream>
using namespace std;
int main() {
	int m, n, i = 0, M, N;
	int mem[100000][2]{};
	int** ans = new int* [10000];
	for (int i = 0; i < 10000; i++) {
		ans[i] = new int[10000];
		for (int j = 0; j < 10000; j++) {
			ans[i][j] = 0;
		}
	}
	cin >> m >> n;
	M = m; N = n;
	while (ans[M][N]==0) {
		if (m == 0) ans[m][n] = n + 1;
		else if (n == 0) {
			if (ans[m - 1][1] != 0) ans[m][n] = ans[m - 1][1];
			else {
				i++;
				mem[i][0] = m;
				mem[i][1] = n;
				m--;
				n = 1;
				continue;
			}
		}
		else {
			if (ans[m][n - 1] != 0) {
				if (ans[m - 1][ans[m][n - 1]] != 0) ans[m][n] = ans[m - 1][ans[m][n - 1]];
				else {
					i++;
					mem[i][0] = m;
					mem[i][1] = n;
					n = ans[m][n - 1];
					m--;
					continue;
				}
			}
			else {
				i++;
				mem[i][0] = m;
				mem[i][1] = n;
				n--;
				continue;
			}
		}
		if (i != 0) {
			m = mem[i][0];
			n = mem[i][1];
			i--;
		}
	}
	cout << ans[m][n];
	return 0;
}