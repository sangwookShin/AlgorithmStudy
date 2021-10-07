#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, x, y, k;
int arr[21][21]; //지도
vector<int> cmd; //명령

int dice[7] = { 0, }; //1위 2북 3동 4서 5남 6아래

//동 서 북 남
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void Roll(int d) {

    int d1, d2, d3, d4, d5, d6;
    d1 = dice[1];
    d2 = dice[2];
    d3 = dice[3];
    d4 = dice[4];
    d5 = dice[5];
    d6 = dice[6];

    if (d == 0) { //동
        dice[1] = d4;
        dice[3] = d1;
        dice[6] = d3;
        dice[4] = d6;
    }
    else if (d == 1) { //서
        dice[1] = d3;
        dice[3] = d6;
        dice[6] = d4;
        dice[4] = d1;
    }
    else if (d == 2) { //북
        dice[1] = d5;
        dice[2] = d1;
        dice[5] = d6;
        dice[6] = d2;
    }
    else if (d == 3) { //남
        dice[1] = d2;
        dice[2] = d6;
        dice[5] = d1;
        dice[6] = d5;
    }

    return;
}

void solve() {

    for (int i = 0; i < cmd.size(); i++) {

        int nx = x + dx[cmd[i]];
        int ny = y + dy[cmd[i]];
        int d = cmd[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
            continue;
        }

        Roll(d);

        if (arr[nx][ny] == 0) {
            arr[nx][ny] = dice[6];
        }
        else {
            dice[6] = arr[nx][ny];
            arr[nx][ny] = 0;
        }

        cout << dice[1] << "\n";

        x = nx;
        y = ny;
    }

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> x >> y >> k;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        cmd.push_back(a - 1);
    }

    solve();

    return 0;
}