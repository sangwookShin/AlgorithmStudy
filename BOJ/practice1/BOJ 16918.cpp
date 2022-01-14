#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char arr[200][200];
int r, c, n;
int boom[200][200];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void install_boom(int t) {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == '.') {
                arr[i][j] = 'O';
                boom[i][j] = t + 3;
            }
        }
    }
}

void boomboom(int t) {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (boom[i][j] == t) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
                        continue;
                    }
                    if (arr[nx][ny] == '.') {
                        continue;
                    }
                    arr[nx][ny] = '.';
                } //for
                arr[i][j] = '.';
                boom[i][j] = 0;
            } //if
        } //for
    } //for

}

void solve() {

    int t = 2;
    while (1) {

        if (t == n + 1) {
            break;
        }

        if (t % 2 == 0) {
            install_boom(t);
        }
        else {
            boomboom(t);
        }
        t++;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> n;

    for (int i = 0; i < r; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < c; j++) {
            arr[i][j] = tmp[j];
            if (arr[i][j] == 'O') {
                boom[i][j] = 3;
            }
        }
    }

    solve();


    return 0;
}