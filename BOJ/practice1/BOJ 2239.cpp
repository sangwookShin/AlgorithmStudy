#include <iostream>
#include <vector>
using namespace std;

int arr[9][9];
int cnt = 0; //채워야하는 개수
vector<pair<int, int>> blank; //채워야하는 칸
bool finish = false;

bool check(int x, int y) {

    for (int i = 0; i < 9; i++) { //행 검사
        if (arr[x][y] == arr[x][i] && i != y) {
            return false;
        }
        if (arr[x][y] == arr[i][y] && i != x) { //열 검사
            return false;
        }
    }

    int dx = x / 3;
    int dy = y / 3;

    for (int i = 3 * dx; i < 3 * dx + 3; i++) { // 3*3사각형 검사
        for (int j = 3 * dy; j < 3 * dy + 3; j++) {
            if (arr[x][y] == arr[i][j]) {
                if (i != x && y != j) {
                    return false;
                }
            }
        }
    }

    return true;
}

void DFS(int n) {

    if (n == cnt) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j];
            }
            cout << "\n";
        }
        finish = true;
        return;
    } //if

    for (int i = 1; i <= 9; i++) {

        arr[blank[n].first][blank[n].second] = i;
        if (check(blank[n].first, blank[n].second)) {
            DFS(n + 1);
        }
        if (finish == true) {
            return;
        }

    } //for
    arr[blank[n].first][blank[n].second] = 0;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 9; j++) {
            arr[i][j] = tmp[j] - '0';
            if (arr[i][j] == 0) {
                blank.push_back({ i,j });
                cnt++;
            }
        }
    }

    DFS(0);

    return 0;
}