#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class disjoint_set {
	int* parent;
	int* rank;
public:
	disjoint_set(int n) {
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}
	int find(int i) {
		if (parent[i] == i) return i;
		return parent[i] = find(parent[i]);
	}
	void Union(int i, int j) {
		int pi, pj;
		pi = find(i);
		pj = find(j);
		if (pi == pj) return;
		if (rank[pi] < rank[pj]) parent[pi] = pj;
		else if (rank[pi] > rank[pj]) parent[pj] = pi;
		else {
			parent[pi] = pj;
			rank[pj] += 1;
		}
	}
};
class Graph {
	vector<vector<int>> edgeList;
	int V;
public:
	Graph(int n) { V = n; }
	void AddEdge(int u, int v, int w) {
		edgeList.push_back({ w,u,v });
	}
	void Kruskal();

};

int main() {
	int V, u, v, w, E;
	cin >> V >> E;
	Graph G(V);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		G.AddEdge(u, v, w);
	}
	G.Kruskal();
}

void Graph::Kruskal() {
	sort(edgeList.begin(), edgeList.end());
	disjoint_set S(V);
	int ans = 0;
	for (auto edge : edgeList) {
		if (S.find(edge[1]) != S.find(edge[2])) {
			S.Union(edge[1], edge[2]);
			ans += edge[0];
		}
	}
	cout << ans;
}

