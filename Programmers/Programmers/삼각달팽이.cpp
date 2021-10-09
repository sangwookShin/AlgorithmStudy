#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1001][1001] = { 0, };
    int dir = 0; //방향 0아래, 1오른쪽, 2왼쪽위대각선
    int x = 0, y = 0;
    int num = 1;

    for (int i = 0; i < n; i++) {

        if (dir == 0) { //아래

            for (int j = i; j < n; j++) {
                arr[x][y] = num;
                num++;
                x++;
            }
            x--;
            y++;
            dir = 1;
        }
        else if (dir == 1) { //오른쪽

            for (int j = i; j < n; j++) {
                arr[x][y] = num;
                num++;
                y++;
            }
            x--;
            y -= 2;
            dir = 2;
        }
        else if (dir == 2) { //왼쪽위

            for (int j = i; j < n; j++) {
                arr[x][y] = num;
                num++;
                x--;
                y--;
            }
            x += 2;
            y++;
            dir = 0;
        }
    } //for

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(arr[i][j]);
        }
    }

    return answer;
}