#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, K;

void solve() {

    int visit[100001];

    for (int i = 0; i <= 100000; i++) {
        visit[i] = 98765431;
    }

    queue<int> q;
    q.push(N);
    visit[N] = 0;

    while (!q.empty()) {

        int x = q.front();
        q.pop();

        if (x == K) {
            cout << visit[K];
            return;
        }

        if (x + 1 < 100001 && visit[x + 1] > visit[x] + 1) {
            q.push(x + 1);
            visit[x + 1] = visit[x] + 1;
        }
        if (x - 1 >= 0 && visit[x - 1] > visit[x] + 1) {
            q.push(x - 1);
            visit[x - 1] = visit[x] + 1;
        }
        if (x * 2 < 100001 && visit[x * 2] > visit[x]) {
            q.push(x * 2);
            visit[x * 2] = visit[x];
        }

    } //while

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    solve();

    return 0;
}