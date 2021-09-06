#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int alpha[27];
vector<string> word;

bool cmp(int i, int j) {
	return j < i;
}

void solve() {

	for (int i = 0; i < word.size(); i++) {

		int sup = 1;

		for (int j = word[i].length() - 1; j >= 0; j--) {

			int tmp = word[i][j] - 'A';
			alpha[tmp] = alpha[tmp] + sup;
			sup = sup * 10;
		}
	}

	sort(alpha, alpha + 26, cmp);

	int result = 0;
	int n = 9;
	for (int i = 0; i < 26; i++) {

		if (alpha[i] == 0) {
			break;
		}

		result = result + (alpha[i] * n);
		n--;
	}

	cout << result;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		word.push_back(tmp);
	}


	solve();

	return 0;
}