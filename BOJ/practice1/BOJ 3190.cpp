#include <iostream>
#include <queue>
using namespace std;

int N, K, T;
int board[101][101];
bool snake[101][101]; //뱀 몸통이 있는지
int dx[] = { -1,0,1,0 }; //방향 상-0 우-1 하-2 좌-3
int dy[] = { 0,1,0,-1 };

char time_d[10001]; //각 초의 방향

void solve() {

    for (int i = 0; i < T; i++) {
        int t;
        char d;
        cin >> t >> d;
        time_d[t] = d;
    }

    queue<pair<int, int>> q; //뱀의 몸통

    //처음
    q.push({ 1,1 });
    snake[1][1] = true;
    int now_dir = 1; //방향
    int now_time = 0; //현재 시간

    while (1) {

        now_time++;

        int nx = q.back().first + dx[now_dir];
        int ny = q.back().second + dy[now_dir];

        if (nx < 1 || ny < 1 || nx > N || ny > N) { //벽에 부딪히면 종료
            break;
        }

        q.push({ nx, ny });

        if (time_d[now_time] == 'L') { //방향 전환
            now_dir--;
            if (now_dir == -1) {
                now_dir = 3;
            }
        }
        else if (time_d[now_time] == 'D') {
            now_dir++;
            if (now_dir == 4) {
                now_dir = 0;
            }
        } //else if

        if (board[nx][ny] == 1) { //사과가 있으면?
            board[nx][ny] = 0;
        }
        else { //사과가 없으면?
            if (snake[nx][ny] == true) { //몸에 부딪히면
                break;
            }
            snake[q.front().first][q.front().second] = false;
            q.pop();
        }


        if (snake[nx][ny] == true) { //몸에 부딪히면
            break;
        }
        else {
            snake[nx][ny] = true;
        }

    } //while

    cout << now_time;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < K; i++) { //사과 위치 1 저장
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }

    cin >> T;

    solve();

    return 0;
}