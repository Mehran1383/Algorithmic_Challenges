#include <iostream>
using namespace std;
//Algorithm perm(a,k,n)
void Perm(char*, int, int);
int main() {
	int n;
	cin >> n;
	char* a = new char[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << endl;
	Perm(a, 0, n);
	return 0;
}
void Perm(char* a, int k, int n) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";//Output permutation
		}
		cout << endl;
	}
	else {//a[k:n] has more than one permutation
		for (int i = k , t; i < n; i++) {//Generate these recursively
			t = a[k]; a[k] = a[i]; a[i] = t;
			Perm(a, k + 1, n);//All permutations of a[k+1:n]
			t = a[k]; a[k] = a[i]; a[i] = t;
		}
	}
}