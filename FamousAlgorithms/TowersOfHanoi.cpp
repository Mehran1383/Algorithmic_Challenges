#include <iostream>
using namespace std;
//TowersOfHanoi(n,x,y,z)
//Move the top n disks from tower x to tower y
void TowersOfHanoi(int,int,int,int);
int main() {
	int n, x = 1, y = 2, z = 3;
	cin >> n;
	TowersOfHanoi(n, x, y, z);
	return 0;
}
void TowersOfHanoi(int n,int x,int y,int z) {
	if (n >= 1) {
		TowersOfHanoi(n - 1, x, z, y);
		cout << "move top disk from tower " << x << " to top of tower " << y << endl;
		TowersOfHanoi(n - 1, z, y, x);
	}
}