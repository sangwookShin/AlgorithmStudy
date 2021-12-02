#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

char arr[12][6];

bool cmp(pair<int, int> a, pair<int, int> b) {

    if (a.second < b.second) {
        return true;
    }
    else if (a.second == b.second) {
        if (a.first < b.first) {
            return true;
        }
        return false;
    }

    return false;
}

void BFS() {

    queue<pair<int, int>> q;
    int cnt = 0;

    while (1) {

        vector<pair<int, int>> v; //연쇄시킬 좌표
        bool visit[12][6] = { false, };

        for (int x = 11; x >= 0; x--) {
            for (int y = 0; y < 6; y++) {

                if (arr[x][y] == '.') {
                    continue;
                }
                else {

                    queue<pair<int, int>> del; //연쇄될 것들
                    char color = arr[x][y];
                    q.push({ x,y });
                    visit[x][y] = true;

                    while (!q.empty()) { //색이 같으면 q에 넣는다.

                        int a = q.front().first;
                        int b = q.front().second;
                        del.push({ a,b });
                        q.pop();

                        for (int i = 0; i < 4; i++) {
                            int nx = a + dx[i];
                            int ny = b + dy[i];

                            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) {
                                continue;
                            }

                            if (!visit[nx][ny] && color == arr[nx][ny]) {
                                visit[nx][ny] = true;
                                q.push({ nx,ny });
                            }
                        }
                    } //while

                    if (del.size() >= 4) { //4개이상이면 v에 넣음

                        while (!del.empty()) {
                            v.push_back({ del.front().first, del.front().second });
                            del.pop();
                        }
                    } //if
                } //else

            } //for
        } //for

        if (v.size() > 0) { //연쇄시킬 것들이 있을 경우

            sort(v.begin(), v.end(), cmp);

            for (int i = 0; i < v.size(); i++) {

                for (int j = v[i].first; j > 0; j--) {
                    arr[j][v[i].second] = arr[j - 1][v[i].second];
                }
                arr[0][v[i].second] = '.';
            }
            cnt++;
        } //if
        else {
            break;
        }

    } //while

    cout << cnt;
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 12; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 6; j++) {
            arr[i][j] = tmp[j];
        }
    }

    BFS();

    return 0;

}