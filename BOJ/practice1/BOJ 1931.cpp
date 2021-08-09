#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;

void solve() {

	int cnt = 0;
	int Start = 0;

	for (int i = 0; i < v.size(); i++) {

		int BeginTime = v[i].second;
		int EndTime = v[i].first;

		if (Start <= BeginTime) {
			Start = EndTime;
			cnt++;
		}
	}
	cout << cnt;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {

		int a, b;
		cin >> a >> b;
		v.push_back({ b, a });
	}

	sort(v.begin(), v.end());

	solve();

	return 0;
}