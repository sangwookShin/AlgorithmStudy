#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int V, E; //정점, 간선
int parent[10001];
int result = 0;
vector<pair<int, pair<int, int>>> g;

int Find(int n) {

	if (parent[n] == n) {
		return n;
	}
	else {
		return parent[n] = Find(parent[n]);
	}
}

bool SameParent(int a, int b) {

	a = Find(a);
	b = Find(b);

	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

void Union(int a, int b) {

	a = Find(a);
	b = Find(b);

	if (a != b) {
		parent[a] = b;
	}
}

void MST() {

	for (int i = 0; i < E; i++) {

		if (SameParent(g[i].second.first, g[i].second.second) == false) {
			Union(g[i].second.first, g[i].second.second);
			result = result + g[i].first;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		g.push_back({ C, {A, B} });
	}

	sort(g.begin(), g.end());

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	MST();

	cout << result;

	return 0;
}