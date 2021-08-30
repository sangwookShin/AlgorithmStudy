#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int zero = 0;
vector<int> result;
vector<int> m, p;

void solve() {

	sort(p.begin(), p.end());
	sort(m.begin(), m.end());

	if (p.size() == 1) {
		result.push_back(p[0]);
	}
	else if (p.size() > 1) {
		//¾ç¼ö
		if (p.size() % 2 == 0) { //Â¦¼ö°³
			for (int i = 0; i <= p.size() - 2; i = i + 2) {
				int sum = p[i] * p[i + 1];
				result.push_back(sum);
			}
		}
		else { //È¦¼ö°³
			for (int i = 1; i <= p.size() - 2; i = i + 2) {
				int sum = p[i] * p[i + 1];
				result.push_back(sum);
			}
			result.push_back(p[0]);
		}
	}

	if (m.size() == 1) {
		if (zero == 0) {
			result.push_back(m[0]);
		}
		else {
			zero--;
		}
	}
	else if (m.size() > 1) {
		//À½¼ö
		if (m.size() % 2 == 0) { //Â¦¼ö°³
			for (int i = 0; i <= m.size() - 2; i = i + 2) {
				int sum = m[i] * m[i + 1];
				result.push_back(sum);
			}
		}
		else { //È¦¼ö°³
			for (int i = 0; i <= m.size() - 3; i = i + 2) {
				int sum = m[i] * m[i + 1];
				result.push_back(sum);
			}
			if (zero == 0) {
				result.push_back(m[m.size() - 1]);
			}
			else {
				zero--;
			}
		}
	}

	//ÃÖÁ¾ÇÕ
	int sum = 0;

	for (int i = 0; i < result.size(); i++) {
		sum += result[i];
	}
	cout << sum;

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;

		if (t > 0 && t != 1) {
			p.push_back(t);
		}
		else if (t == 0) {
			zero++;
		}
		else if (t == 1) {
			result.push_back(t);
		}
		else {
			m.push_back(t);
		}
	}

	solve();

	return 0;
}