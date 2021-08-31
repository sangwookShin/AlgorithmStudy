#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001][4];
int maxdp[4];
int mindp[4];

void solve() {

	//max
	for (int i = 2; i <= n; i++) {

		int max1 = maxdp[1];
		int max2 = maxdp[2];
		int max3 = maxdp[3];

		maxdp[1] = max(max1, max2) + arr[i][1];
		maxdp[2] = max(max(max1, max2), max3) + arr[i][2];
		maxdp[3] = max(max2, max3) + arr[i][3];
	}

	cout << max(maxdp[1], max(maxdp[2], maxdp[3])) << " ";

	//min
	for (int i = 2; i <= n; i++) {

		int min1 = mindp[1];
		int min2 = mindp[2];
		int min3 = mindp[3];

		mindp[1] = min(min1, min2) + arr[i][1];
		mindp[2] = min(min(min1, min2), min3) + arr[i][2];
		mindp[3] = min(min2, min3) + arr[i][3];
	}

	cout << min(mindp[1], min(mindp[2], mindp[3]));
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}
	maxdp[1] = arr[1][1];
	maxdp[2] = arr[1][2];
	maxdp[3] = arr[1][3];

	mindp[1] = arr[1][1];
	mindp[2] = arr[1][2];
	mindp[3] = arr[1][3];

	solve();

	return 0;
}