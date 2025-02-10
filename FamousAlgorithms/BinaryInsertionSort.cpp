#include <iostream>
using namespace std;
int binarySearch(int*, int, int, int);
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int j = 1, key, i,loc; j < n; j++) {
		key = a[j];
		i = j - 1;
		loc = binarySearch(a, key, 0, i);
		while (i >= loc) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}
int binarySearch(int* a, int key, int low, int high) {
	if (high <= low) return (key > a[low]) ? low + 1 : low;
	int mid = (low + high) / 2;
	if (key == a[mid]) return mid + 1;
	if (key > a[mid]) return binarySearch(a, key, mid + 1, high);
	return binarySearch(a, key, low, mid - 1);
}