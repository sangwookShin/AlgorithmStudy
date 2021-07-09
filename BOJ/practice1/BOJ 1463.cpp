#include <iostream>
#include <algorithm>

using namespace std;

int N;
int a[1000001];
void solve() {

	a[1] = 0;
	a[2] = 1;

	for (int i = 3; i < 1000001; i++) {

		a[i] = a[i - 1] + 1;
		if (i % 2 == 0) {
			a[i] = min(a[i], a[i / 2] + 1);
		}
		if (i % 3 == 0) {
			a[i] = min(a[i], a[i / 3] + 1);
		}
	}

	cout << a[N];
}

int main() {

	cin >> N;
	solve();

	return 0;
}