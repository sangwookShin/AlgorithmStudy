#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[8];
bool visit[8];
vector<int> v;

void DFS(int cnt) {

    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visit[i] == true) {
            continue;
        }

        visit[i] = true;
        arr[cnt] = v[i];
        DFS(cnt + 1);
        visit[i] = false;
    }

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    DFS(0);

    return 0;
}