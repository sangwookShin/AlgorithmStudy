#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
char arr[50][50];
bool visit[50][50] = { false, };

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool check = false;

void DFS(int x, int y, int direction, int cnt, int start_x, int start_y) { //DFSŽ����ġ x,y / ���� / ������̴��� / ��ó��Ž����ġ

    if (check == true) {
        return;
    }

    for (int i = 0; i < 4; i++) {

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
            continue;
        }

        if (!visit[nx][ny]) { //�湮���� ��
            if (arr[x][y] == arr[nx][ny]) { //���� ������
                visit[nx][ny] = true;
                if (i == direction) { //��� ���� �����̸�
                    DFS(nx, ny, direction, cnt, start_x, start_y);
                }
                else { //���ϰ��
                    DFS(nx, ny, i, cnt + 1, start_x, start_y);
                }
            } //if

        } //if
        else { //�湮�� ��
            if (nx == start_x && ny == start_y && cnt >= 4) { //4�������� �簢���̵ǰ�, ��ǥ�� ��ó�� ��ġ�� ������ Yes
                check = true;
                return;
            }
        }
    } //for

}

void solve() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            memset(visit, false, sizeof(visit));
            int start_x = i;
            int start_y = j;

            for (int k = 0; k < 4; k++) {

                memset(visit, false, sizeof(visit));
                visit[i][j] = true;
                DFS(i, j, k, 1, start_x, start_y);
                if (check == true) {
                    cout << "Yes";
                    return;
                }
            }

        } //for
    } //for

    cout << "No";
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            arr[i][j] = tmp[j];
        }
    }

    solve();

    return 0;

}