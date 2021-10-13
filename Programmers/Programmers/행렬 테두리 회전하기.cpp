#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int arr[101][101];
    int num = 1;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            arr[i][j] = num;
            num++;
        }
    }

    for (int i = 0; i < queries.size(); i++) {
        //(x1, y1) (x2, y2)
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];

        int min_num = arr[x1][y1]; //최솟값
        int tmp = min_num; //돌리기위해 저장 / 첫번째 값

        for (int j = x1; j < x2; j++) { //왼쪽
            min_num = min(min_num, arr[j][y1]);
            arr[j][y1] = arr[j + 1][y1];
        }
        for (int j = y1; j < y2; j++) { //아래
            min_num = min(min_num, arr[x2][j]);
            arr[x2][j] = arr[x2][j + 1];
        }
        for (int j = x2; j > x1; j--) { //오른쪽
            min_num = min(min_num, arr[j][y2]);
            arr[j][y2] = arr[j - 1][y2];
        }
        for (int j = y2; j > y1; j--) { //위
            min_num = min(min_num, arr[x1][j]);
            arr[x1][j] = arr[x1][j - 1];
        }
        arr[x1][y1 + 1] = tmp;

        answer.push_back(min_num);
    } //for

    return answer;
}