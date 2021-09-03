#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

char building[31][31][31]; //Ãþ Çà ¿­
int visit[31][31][31] = { 0, };	//Ãþ Çà ¿­
int startA, startB, startC, endA, endB, endC; //Çà ¿­ Ãþ
int L, R, C;

int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { 0,0,0,0,-1,1 };
int df[] = { 1,-1,0,0,0,0 };

void BFS(int a, int b, int c) {

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {a, b},{c, 0} }); //Ãþ, x, y, ÀÌµ¿È½¼ö
	visit[a][b][c] = 1;

	while (!q.empty()) {

		int floor = q.front().first.first;
		int x = q.front().first.second;
		int y = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (floor == endC && x == endA && y == endB) {
			cout << "Escaped in " << cnt << " minute(s)." << endl;
			return;
		}

		for (int i = 0; i < 6; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];
			int nf = floor + df[i];

			if (nx < 0 || ny < 0 || nf < 0 || nx >= R || ny >= C || nf >= L) {
				continue;
			}

			if (building[nf][nx][ny] == '#') {
				continue;
			}

			if (building[nf][nx][ny] == '.' || building[nf][nx][ny] == 'E') {
				if (visit[nf][nx][ny] == 0) {
					visit[nf][nx][ny] = 1;
					q.push({ {nf,nx}, {ny, cnt + 1} });
				}
			}
		}
	}

	cout << "Trapped!" << endl;
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {

		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) {	//Á¾·á
			return 0;
		}

		//ÃÊ±âÈ­
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < L; i++) {	//ÀÔ·Â
			for (int j = 0; j < R; j++) {
				string tmp;
				cin >> tmp;
				for (int k = 0; k < C; k++) {
					building[i][j][k] = tmp[k];
					if (tmp[k] == 'S') {
						startA = j;
						startB = k;
						startC = i;
					}
					if (tmp[k] == 'E') {
						endA = j;
						endB = k;
						endC = i;
					}
				}
			}
		}
		BFS(startC, startA, startB);
	}

	return 0;
}