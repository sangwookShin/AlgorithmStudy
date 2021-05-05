#include <iostream>
#include <vector>

using namespace std;

int N, x, y, d, g;
int m[101][101] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<int> directionInformation;

void makeDragoncurve() {

    int s = directionInformation.size();

    for (int i = s - 1; i >= 0; i--) {

        int nd = (directionInformation[i] + 1) % 4;

        x = x + dx[nd];
        y = y + dy[nd];
        m[y][x] = 1;
        directionInformation.push_back(nd);
    }
}

int count_square() {

    int cnt = 0;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {

            if (m[i][j] == 1 && m[i + 1][j] == 1 && m[i][j + 1] == 1 && m[i + 1][j + 1] == 1) {
                cnt++;
            }
        }
    }

    return cnt;
}

void solve() {

    for (int i = 0; i < N; i++) {

        cin >> x >> y >> d >> g;

        directionInformation.clear();

        m[y][x] = 1;
        x = x + dx[d];
        y = y + dy[d];
        m[y][x] = 1;

        directionInformation.push_back(d);

        for (int j = 0; j < g; j++) {
            makeDragoncurve();
        }
    }

    cout << count_square();
}

int main() {

    cin >> N;

    solve();

    return 0;
}