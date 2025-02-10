#include <iostream>
using namespace std;
//Algorithm SelectionSort(a,n)
//Sort the array a[1:n] into nondecreasing order.
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0, j, t; i < n - 1; i++) {
		j = i;
		for (int k = i + 1; k < n; k++) {
			if (a[k] < a[j]) j = k;
		}
		t = a[i]; a[i] = a[j]; a[j] = t;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}