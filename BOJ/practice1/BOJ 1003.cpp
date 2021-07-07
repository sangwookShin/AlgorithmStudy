#include <iostream>
#include <algorithm>

using namespace std;

int fb[41];
int a[1000];

void solve() {

	fb[0] = 1;
	fb[1] = 0;
	fb[2] = 1;

	for (int i = 3; i < 41; i++) {
		fb[i] = fb[i - 1] + fb[i - 2];
	}
}

int main() {

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		a[i] = N;
	}

	solve();

	for (int i = 0; i < T; i++) {

		if (a[i] == 0) {
			cout << 1 << " " << 0 << endl;
		}
		else if (a[i] == 1) {
			cout << 0 << " " << 1 << endl;
		}
		else {
			cout << fb[a[i]] << " " << fb[a[i]] + fb[a[i] - 1] << endl;
		}
	}

	return 0;
}