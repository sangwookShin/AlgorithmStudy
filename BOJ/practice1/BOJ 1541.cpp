#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string stra;

void solve() {

	bool flag = false;
	int result = 0;
	string tmp = "";

	for (int i = 0; i <= stra.length(); i++) {

		if (stra[i] == '+' || stra[i] == '-' || stra[i] == '\0') {

			if (flag == true) {
				result = result - stoi(tmp);
			}
			else if (flag == false) {
				result = result + stoi(tmp);
			}
			if (stra[i] == '-') {
				flag = true;
			}

			tmp = "";
		}
		else {
			tmp = tmp + stra[i];
		}
	}
	cout << result;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> stra;

	solve();

	return 0;
}