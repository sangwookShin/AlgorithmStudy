#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N;
int arr[21][21];
int visit[21][21];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int start_x, start_y; //ó�� �Ʊ����� ��ġ ��,��
int babyshark_size = 2; //�Ʊ����� ũ��
vector<pair<pair<int, int>, int>> shark; //��� �Ÿ�/x��ǥ/y��ǥ

void BFS(int bx, int by) {

    int dis = 987654321;
    queue<pair<int, int>> q;
    q.push({ bx, by });

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                continue;
            }
            if (visit[nx][ny] == 0 && babyshark_size >= arr[nx][ny]) { //�ڱ⺸�� �۰ų� ���� ���
                visit[nx][ny] = visit[x][y] + 1;
                if (babyshark_size > arr[nx][ny] && arr[nx][ny] != 0) { //�ڱ⺸�� ���� �� �Դ´�
                    if (dis >= visit[nx][ny]) {
                        dis = visit[nx][ny];
                        shark.push_back({ {dis, nx},ny });
                    }
                }
                q.push({ nx,ny });
            } //if
        } //for
    } //while
}

void solve() {

    int result = 0;
    int cnt = 0;

    while (1) {

        memset(visit, 0, sizeof(visit));
        shark.clear();
        BFS(start_x, start_y);

        if (shark.empty()) {
            break;
        }
        else {
            sort(shark.begin(), shark.end());
            cnt++; //���� ��
            result = result + shark.front().first.first; //�� ���
            arr[shark.front().first.second][shark.front().second] = 0; //�Ծ����� 0���� ����

            //���������� ���� ��ġ �缳��
            start_x = shark.front().first.second;
            start_y = shark.front().second;

            //�Ʊ��� ũ���� ����ŭ �� �Ծ��� �� �Ʊ��� ũ�� ����
            if (babyshark_size == cnt) {
                babyshark_size++;
                cnt = 0;
            }
        }
    } //while

    cout << result;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                arr[i][j] = 0;
                start_x = i;
                start_y = j;
            }
        }
    }

    solve();

    return 0;
}