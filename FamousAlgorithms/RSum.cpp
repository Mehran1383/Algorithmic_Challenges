#include <iostream>
using namespace std;
//Algorithm RSum(a,n)
float RSum(float*, int);
int main() {
	int n;
	cin >> n;
	float* a = new float[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << RSum(a, n);
	return 0;
}
float RSum(float* a , int n) {
	if (n <= 0) return 0.0;
	return RSum(a, n - 1) + a[n - 1];
}