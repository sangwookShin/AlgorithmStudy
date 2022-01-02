#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[5][5];
int call[26];
bool bingo[5][5] = { false, };

void solve() {

    for (int i = 1; i <= 25; i++) {

        int total_cnt = 0; //빙고 개수

        for (int j = 0; j < 5; j++) { //숫자 찾기
            for (int k = 0; k < 5; k++) {
                if (arr[j][k] == call[i]) {
                    bingo[j][k] = true;
                    break;
                }
            }
        } //for

        //가로 빙고 검사
        for (int j = 0; j < 5; j++) {
            if (bingo[j][0] && bingo[j][1] && bingo[j][2] && bingo[j][3] && bingo[j][4]) {
                total_cnt++;
            }
        }

        //세로 빙고 검사
        for (int j = 0; j < 5; j++) {
            if (bingo[0][j] && bingo[1][j] && bingo[2][j] && bingo[3][j] && bingo[4][j]) {
                total_cnt++;
            }
        }

        //대각선 검사
        if (bingo[0][0] && bingo[1][1] && bingo[2][2] && bingo[3][3] && bingo[4][4]) {
            total_cnt++;
        }
        if (bingo[0][4] && bingo[1][3] && bingo[2][2] && bingo[3][1] && bingo[4][0]) {
            total_cnt++;
        }

        if (total_cnt >= 3) {
            cout << i;
            return;
        }
    } //for

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= 25; i++) {
        cin >> call[i];
    }

    solve();

    return 0;
}