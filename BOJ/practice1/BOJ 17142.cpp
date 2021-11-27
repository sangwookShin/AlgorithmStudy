#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[51][51];
int visit[51][51]; //�ɸ� �ð�
int result = 987654321;
int is_zero = 0; //0�� ����

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool check[10]; //Ȱ����ų ���̷��� ����
vector<pair<int, int>> v; //���̷��� ��ġ

void spread_virus(queue<pair<int, int>> q) { //BFS

    int time = 0;
    int infect = 0; //������ ��
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

            if (arr[nx][ny] != 1 && visit[nx][ny] == -1) {
                visit[nx][ny] = visit[x][y] + 1;
                if (arr[nx][ny] == 0) { //��������� ����
                    time = visit[nx][ny];
                    infect++;
                }
                q.push({ nx,ny });
            }
        }

    } //while

    if (is_zero == infect) { //������ ���� ó���� ����� ������ ��ġ�ϸ� ����� ����
        result = min(result, time);
    }

}

void solve(int idx, int cnt) { //��Ʈ��ŷ

    if (cnt == M) {

        queue<pair<int, int>> q;
        memset(visit, -1, sizeof(visit));

        for (int i = 0; i < v.size(); i++) {
            if (check[i] == true) { //������ų �ڸ�
                q.push({ v[i].first, v[i].second });
                visit[v[i].first][v[i].second] = 0;
            }
        }

        spread_virus(q);
        return;
    } //if

    for (int i = idx; i < v.size(); i++) { //��Ʈ��ŷ
        if (check[i] == true) {
            continue;
        }
        check[i] = true;
        solve(i + 1, cnt + 1);
        check[i] = false;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                v.push_back({ i,j });
            }
            else if (arr[i][j] == 0) {
                is_zero++;
            }
        }
    }

    solve(0, 0);

    if (result == 987654321) {
        cout << -1;
    }
    else {
        cout << result;
    }

    return 0;
}