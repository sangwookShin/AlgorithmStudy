#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;

void solve() {

	int result = 0;

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {

		result = max(result, v[i] * (N - i));
	}
	cout << result;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	solve();

	return 0;
}