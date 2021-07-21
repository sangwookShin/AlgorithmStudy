#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, H;
vector<int> up;
vector<int> down;

void solve() {

	int result = 200001;
	int cnt = 0;
	int i;

	sort(up.begin(), up.end());
	sort(down.begin(), down.end());

	for (i = 1; i <= H; i++) {

		int a = lower_bound(up.begin(), up.end(), i) - up.begin();
		a = a + upper_bound(down.begin(), down.end(), H - i) - down.begin();
		a = N - a;

		if (result > a) {
			result = a;
			cnt = 1;
		}
		else if (result == a) {
			cnt++;
		}

	}

	cout << result << " " << cnt;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> H;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;

		if (i % 2 == 0) { //석순
			up.push_back(t);
		}
		else { //종유석
			down.push_back(t);
		}
	}

	solve();

	return 0;
}