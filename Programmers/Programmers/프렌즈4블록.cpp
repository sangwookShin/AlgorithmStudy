#include <string>
#include <vector>
#include <cstring>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool check = true;

    while (check) {

        check = false;
        bool arr[30][30];
        memset(arr, false, sizeof(arr));

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {

                if (board[i][j] == ' ') {
                    continue;
                }
                char a = board[i][j];

                if (board[i][j + 1] == a && board[i + 1][j] == a && board[i + 1][j + 1] == a) {
                    arr[i][j + 1] = true;
                    arr[i + 1][j] = true;
                    arr[i + 1][j + 1] = true;
                    arr[i][j] = true;
                    check = true;
                } //if
            } //for
        } //for

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (arr[i][j] == true) {
                    answer++;

                    for (int k = i - 1; k >= 0; k--) { //³»¸®±â
                        board[k + 1][j] = board[k][j];
                        board[k][j] = ' ';
                    }
                } //if   
            } //for
        } //for

    } //while

    return answer;
}