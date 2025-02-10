#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	float n, w, l, L = 0;
	unsigned long long int objective = 0;
	cin >> n;
	vector<vector<float>> jobs;
	for (float i = 0; i < n; i++) {
		cin >> w >> l;
		jobs.push_back({ w / l,i,l,w });
	}
	sort(jobs.begin(), jobs.end(), greater<vector<float>>());
	cout << endl;
	for (auto job : jobs) {
		cout << job[1] << " " << job[0] << endl;
		L += job[2];
		objective += L * job[3];
	}
	cout << "Objective function value is : " << objective;
}