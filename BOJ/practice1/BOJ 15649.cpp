#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int visit[9] = { 0, };
int arr[9];
int N, M;

void DFS(int cnt) {

	if (cnt == M) {
		for (int i = 0; i < cnt; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0) {
			arr[cnt] = i;
			visit[i] = 1;
			DFS(cnt + 1);
			visit[i] = 0;
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	DFS(0);

	return 0;
}