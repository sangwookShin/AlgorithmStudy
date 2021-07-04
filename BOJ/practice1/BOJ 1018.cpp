#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char board[50][50];
int N, M;

string WB[8] = {
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"}
};

string BW[8] = {

	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"}
};

int makeWB(int a, int b) {

	int cnt = 0;

	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			if (board[i][j] != WB[i - a][j - b])
				cnt++;
		}
	}

	return cnt;
}

int makeBW(int a, int b) {

	int cnt = 0;
	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			if (board[i][j] != BW[i - a][j - b])
				cnt++;
		}
	}

	return cnt;
}
void solve() {

	int result = 987654321;

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			result = min(result, min(makeBW(i, j), makeWB(i, j)));
		}
	}

	cout << result;
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			board[i][j] = c;
		}
	}

	solve();

	return 0;

}