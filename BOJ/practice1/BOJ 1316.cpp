#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> word;

int solve() {

	int result = 0;
	int flag = 0;

	for (int i = 0; i < N; i++) {

		vector<char> tmp;

		tmp.push_back(word[i][0]);

		for (int j = 1; j <= word[i].size(); j++) {

			if (tmp.back() == word[i][j]) {
				continue;
			}
			else if (tmp.back() != word[i][j]) {

				for (int k = 0; k < tmp.size() - 1; k++) {
					if (tmp[k] == word[i][j]) {
						flag = 1;
					}
				}
				tmp.push_back(word[i][j]);
			}
		}

		if (flag == 0) {
			result++;
		}
		flag = 0;
	}

	return result;
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		word.push_back(s);
	}

	cout << solve();

	return 0;
}