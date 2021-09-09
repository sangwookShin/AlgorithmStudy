#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int sang[500001];
int card[500001];

void solve() {

	sort(sang, sang + N);

	for (int i = 0; i < M; i++) {

		int low = 0;
		int high = N - 1;
		bool check = false;

		while (low <= high) {

			int mid = (low + high) / 2;

			if (sang[mid] == card[i]) {
				cout << 1 << " ";
				check = true;
				break;
			}
			else if (sang[mid] < card[i]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		if (check == false) {
			cout << 0 << " ";
		}

	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> sang[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> card[i];
	}

	solve();

	return 0;
}