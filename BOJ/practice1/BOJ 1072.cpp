#include <iostream>
#include <algorithm>

using namespace std;

long long x, y, z;

void solve() {

	z = 100 * y / x;
	if (z >= 99) {
		cout << "-1";
		return;
	}

	long long low = 0;
	long long high = 1000000000;
	long long tmp;
	while (low <= high) {

		long long mid = (low + high) / 2;

		tmp = (y + mid) * 100 / (x + mid);

		if (z >= tmp) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << low;
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y;

	solve();

	return 0;
}