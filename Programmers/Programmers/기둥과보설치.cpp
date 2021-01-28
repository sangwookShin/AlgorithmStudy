#include <string>
#include <vector>

using namespace std;

int col[101][101] = { 0 };
int bo[101][101] = { 0 };

bool checkCol(int x, int y, int n) {

    if (y == 0) return 1;
    if (col[x][y - 1]) return 1;
    if (bo[x][y] && x < n) return 1;
    if (bo[x - 1][y] && x > 0) return 1;

    return 0;
}

bool checkBo(int x, int y, int n) {

    if (col[x][y - 1]) return 1;
    if (col[x + 1][y - 1] && x < n) return 1;
    if (bo[x + 1][y] && bo[x - 1][y] && x < n && x > 0) return 1;

    return 0;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++) {

        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];

        //기둥 설치
        if (a == 0 && b == 1) {
            if (checkCol(x, y, n) == 1)
                col[x][y] = 1;
        }

        //보 설치
        else if (a == 1 && b == 1) {
            if (checkBo(x, y, n) == 1)
                bo[x][y] = 1;
        }

        //기둥 삭제
        else if (a == 0 && b == 0) {

            col[x][y] = 0;
            if (col[x][y + 1] && !checkCol(x, y + 1, n) && y < n) col[x][y] = 1;
            else if (bo[x - 1][y + 1] && !checkBo(x - 1, y + 1, n) && x > 0 && y < n) col[x][y] = 1;
            else if (bo[x][y + 1] && !checkBo(x, y + 1, n) && y < n) col[x][y] = 1;

        }

        //보 삭제
        else if (a == 1 && b == 0) {

            bo[x][y] = 0;
            if (x > 0 && bo[x - 1][y] && !checkBo(x - 1, y, n)) bo[x][y] = 1;
            else if (x < n && bo[x + 1][y] && !checkBo(x + 1, y, n)) bo[x][y] = 1;
            else if (col[x][y] && !checkCol(x, y, n)) bo[x][y] = 1;
            else if (x < n && col[x + 1][y] && !checkCol(x + 1, y, n)) bo[x][y] = 1;

        }

    }

    //결과
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (col[i][j]) {
                answer.push_back({ i,j,0 });
            }
            if (bo[i][j]) {
                answer.push_back({ i,j,1 });
            }
        }
    }


    return answer;
}