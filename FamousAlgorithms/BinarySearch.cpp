#include <iostream>
using namespace std;
int search(int*, int, int, int);
int main() {
	int n, key, ans;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> key;
	ans = search(a, 0, n - 1, key);
	if (ans == -1) cout << "Not find !";
	else cout << "Find in the " << ans << "th place !";
	return 0;
}
int search(int* a, int low, int high, int key) {
	if (high < low) return -1;
	int mid = (high + low) / 2;
	if (a[mid] == key) return mid;
	if (key > a[mid]) return search(a, mid + 1, high, key);
	return search(a, low, mid - 1, key);
}