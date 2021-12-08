#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int R, C, T;
int arr[50][50];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int air_up, air_down; //����û���� ���κ�, �Ʒ��κ� ��
int add[50][50];
int result = 0;

void spread() { //�̼����� Ȯ��

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            int spread_air = arr[i][j] / 5; //Ȯ��� ��
            int cnt = 0; //Ȯ��� ���� ����
            if (arr[i][j] == 0 || arr[i][j] == -1) { //�̼������� ���ų� ����û���Ⱑ �ִ� �ڸ��� continue
                continue;
            }

            for (int k = 0; k < 4; k++) {

                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
                    continue;
                }
                if (arr[nx][ny] == -1) {
                    continue;
                }

                add[nx][ny] += spread_air;
                cnt++;
            } //for

            arr[i][j] -= (cnt * spread_air);

        } //for
    } //for

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            arr[i][j] += add[i][j];
        }
    }

    memset(add, 0, sizeof(add));
}

void clean_air() { //����û���� Ȯ��

   //����û����� ���� �̼�����
    result -= arr[air_up - 1][0];
    result -= arr[air_down + 1][0];

    //����û���� ���κ�
    for (int i = air_up - 1; i > 0; i--) {
        arr[i][0] = arr[i - 1][0];
    }
    for (int i = 0; i < C - 1; i++) {
        arr[0][i] = arr[0][i + 1];
    }
    for (int i = 1; i <= air_up; i++) {
        arr[i - 1][C - 1] = arr[i][C - 1];
    }
    for (int i = C - 1; i > 1; i--) {
        arr[air_up][i] = arr[air_up][i - 1];
    }
    arr[air_up][1] = 0;

    //����û���� �Ʒ��κ�
    for (int i = air_down + 1; i < R - 1; i++) {
        arr[i][0] = arr[i + 1][0];
    }
    for (int i = 0; i < C - 1; i++) {
        arr[R - 1][i] = arr[R - 1][i + 1];
    }
    for (int i = R - 1; i >= air_down; i--) {
        arr[i][C - 1] = arr[i - 1][C - 1];
    }
    for (int i = C - 1; i > 1; i--) {
        arr[air_down][i] = arr[air_down][i - 1];
    }
    arr[air_down][1] = 0;
}

void solve() {

    for (int i = 0; i < T; i++) {
        //�̼����� Ȯ��
        spread();
        //����û���� Ȯ��
        clean_air();
    }

    cout << result;
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> T;
    bool flag = false;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1 && flag == false) {
                air_up = i;
                air_down = i + 1;
                flag = true;
            }
            else if (arr[i][j] != -1) {
                result += arr[i][j];
            }
        }
    }

    solve();

    return 0;

}