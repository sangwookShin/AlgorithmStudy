#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;

void solve() {

	string s = "";
	int cnt = 0;
	int series = 665;

	while (1) {

		if (cnt == N)
			break;

		series++;
		s = to_string(series);

		if (s.find("666") != -1) {
			cnt++;
		}
	}

	cout << series;
}

int main() {

	cin >> N;

	solve();

	return 0;

}