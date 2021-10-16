#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char arr[3][3];

int x_cnt, o_cnt, dot_cnt; //x개수, o개수, .개수

int check_Bingo(char c) {

    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        //가로
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == c) {
            cnt++;
        }
        //세로
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] == c) {
            cnt++;
        }
    }

    //대각선
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == c) {
        cnt++;
    }
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] == c) {
        cnt++;
    }

    return cnt;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {

        string tmp = "";
        cin >> tmp;
        if (tmp == "end") {
            break;
        }

        int a = 0;
        x_cnt = 0;
        o_cnt = 0;
        dot_cnt = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                arr[i][j] = tmp[a];
                a++;
                if (arr[i][j] == '.') {
                    dot_cnt++;
                }
                else if (arr[i][j] == 'X') {
                    x_cnt++;
                }
                else if (arr[i][j] == 'O') {
                    o_cnt++;
                }
            } //for
        }//for

        bool check = true;

        if (dot_cnt == 0) { // . 이 없음
            if (x_cnt != o_cnt + 1) {
                check = false;
            }
            if (check_Bingo('O') > 0) {
                check = false;
            }
        }
        else if (dot_cnt != 0 && dot_cnt % 2 == 0) { // . 이 짝수개 - X가 이겨야 함
            if (x_cnt != o_cnt + 1) {
                check = false;
            }
            if (check_Bingo('O') > 0) {
                check = false;
            }
            if (check_Bingo('X') == 0) {
                check = false;
            }
        }
        else { // . 이 홀수개
            if (x_cnt != o_cnt) {
                check = false;
            }
            if (check_Bingo('X') > 0) {
                check = false;
            }
            if (check_Bingo('O') == 0) {
                check = false;
            }
        }

        if (check == true) {
            cout << "valid" << "\n";
        }
        else {
            cout << "invalid" << "\n";
        }

    } //while


    return 0;
}