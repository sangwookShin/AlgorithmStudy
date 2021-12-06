#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int result = 0;
int arr[8];
bool visit[8] = { false, };
int N;
vector<int> v;

void c() {

    int sum = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        sum += abs(v[i] - v[i + 1]);
    }
    result = max(result, sum);
}

void DFS(int cnt) {

    if (cnt == N) {
        c();
        return;
    }

    for (int i = 0; i < N; i++) {

        if (visit[i] == true) {
            continue;
        }
        visit[i] = true;
        v.push_back(arr[i]);
        DFS(cnt + 1);
        v.pop_back();
        visit[i] = false;
    }

}

void solve() {

    DFS(0);
    cout << result;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    solve();

    return 0;

}