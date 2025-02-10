#include <iostream>
using namespace std;
int main() {
	int n, result = 0;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) {
		result += A[i];
	}
	cout << "The sum is " << result << endl;
}