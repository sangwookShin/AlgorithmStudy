#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[9];
int visit[9];

void DFS(int n, int cnt) {

	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = n; i <= N; i++) {

		if (visit[i] == 0) {
			arr[cnt] = i;
			visit[i] = 1;
			DFS(i + 1, cnt + 1);
			visit[i] = 0;
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	DFS(1, 0);

	return 0;
}