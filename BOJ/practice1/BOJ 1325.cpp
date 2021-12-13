#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
bool visit[10001];
vector<int> v[10001];
int cnt = 0;
int cur_cnt = 0;

void DFS(int a) {

    visit[a] = true;

    for (int i = 0; i < v[a].size(); i++) {
        int nx = v[a][i];

        if (visit[nx] == false) {
            cnt++;
            DFS(nx);
        }
    }
}
void solve() {

    vector<int> result;

    for (int i = 1; i <= N; i++) {

        memset(visit, false, sizeof(visit));
        cnt = 0;
        DFS(i);

        if (cur_cnt == cnt) {
            result.push_back(i);
        }
        else if (cur_cnt < cnt) {
            cur_cnt = cnt;
            result.clear();
            result.push_back(i);
        }


    } //for

    //결과 출력
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) { //a가 b를 신뢰한다 > b를 해킹하면 a도 해킹 가능
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    solve();

    return 0;
}