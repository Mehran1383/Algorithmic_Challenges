#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 1 , key , i; j < n; j++) {
		key = a[j];//Insert a[j] into the sorted sequence a[1 ... j-1].
		i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}