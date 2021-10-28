#include <string>
#include <vector>

using namespace std;

int zero = 0;
int one = 0;
vector<vector<int>> arr2;

void DFS(int x, int y, int size) {

    bool check_zero = true;
    bool check_one = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr2[i][j] == 0) {
                check_one = false;
            }
            if (arr2[i][j] == 1) {
                check_zero = false;
            }
        } //for
    }//for

    if (check_zero == true) {
        zero++;
        return;
    }
    if (check_one == true) {
        one++;
        return;
    }

    DFS(x, y, size / 2);
    DFS(x, y + size / 2, size / 2);
    DFS(x + size / 2, y, size / 2);
    DFS(x + size / 2, y + size / 2, size / 2);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    arr2 = arr;

    DFS(0, 0, arr.size());
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}