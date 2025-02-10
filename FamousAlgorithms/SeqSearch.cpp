#include <iostream>
using namespace std;
int main() {
	int n, x, location = 0;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	cin >> x;
	while (location < n && A[location] != x) location++;
	if (location == n) cout << "Does not exist !" << endl;
	else cout << location;
}