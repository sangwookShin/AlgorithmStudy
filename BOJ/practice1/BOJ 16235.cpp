#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;
vector<int> tree[11][11]; //살아있는 나무
int energy[11][11]; //양분
int add_energy[11][11]; //추가 양분
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

void springsummer() {

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            if (tree[i][j].size() == 0) { //칸에 나무가 없으면 넘김
                continue;
            }

            int dead_tree = 0; //죽은 나무들의 합
            vector<int> tmp;

            sort(tree[i][j].begin(), tree[i][j].end());

            for (int p = 0; p < tree[i][j].size(); p++) {

                if (energy[i][j] >= tree[i][j][p]) {
                    energy[i][j] -= tree[i][j][p];
                    tmp.push_back(tree[i][j][p] + 1);
                }
                else {
                    dead_tree += (tree[i][j][p] / 2);
                }
            } // for

            tree[i][j].clear();
            for (int q = 0; q < tmp.size(); q++) {
                tree[i][j].push_back(tmp[q]);
            }

            energy[i][j] += dead_tree;
        } //for
    } //for
}

void fall() {

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            if (tree[i][j].size() == 0) { //나무가 없으면 continue
                continue;
            }

            for (int p = 0; p < tree[i][j].size(); p++) {

                if (tree[i][j][p] % 5 == 0) { //나무가 5의배수이면 주변에 나무 1씩 추가
                    for (int q = 0; q < 8; q++) {
                        int nx = i + dx[q];
                        int ny = j + dy[q];

                        if (nx >= 1 && ny >= 1 && nx <= N && ny <= N) {
                            tree[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void winter() { //양분 추가

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            energy[i][j] += add_energy[i][j];
        }
    }
}

void solve() {

    int result = 0;

    for (int i = 0; i < K; i++) {
        //봄 & 여름
        springsummer();
        //가을
        fall();
        //겨울
        winter();
    }

    //검사
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            result += tree[i][j].size();
        }
    }

    cout << result;

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            energy[i][j] = 5;
            cin >> add_energy[i][j];
        }
    }

    for (int i = 1; i <= M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }

    solve();

    return 0;
}