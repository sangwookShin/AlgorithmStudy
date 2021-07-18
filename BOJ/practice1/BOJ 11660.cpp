#include <iostream>

using namespace std;

int N, M;
int board[1025][1025];


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			board[i + 1][j + 1] = board[i + 1][j] + board[i][j + 1] - board[i][j] + a;
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, x, y;

		cin >> a >> b >> x >> y;

		cout << board[x][y] - board[x][b - 1] - board[a - 1][y] + board[a - 1][b - 1] << "\n";

	}

	return 0;
}