#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int arr[100001];
bool visit[100001];
vector<int> result;

void solve() {

    queue<pair<int, int>> q;
    q.push({ n, 0 });
    visit[n] = true;

    while (!q.empty()) {

        int cur = q.front().first;
        int sec = q.front().second;
        q.pop();

        if (cur == k) {

            int i = cur;

            while (i != n) {
                result.push_back(i);
                i = arr[i];
            }
            result.push_back(n);

            cout << sec << endl;
            return;
        }

        if (cur + 1 < 100001 && !visit[cur + 1]) {
            q.push({ cur + 1, sec + 1 });
            visit[cur + 1] = true;
            arr[cur + 1] = cur;
        }
        if (cur - 1 >= 0 && !visit[cur - 1]) {
            q.push({ cur - 1, sec + 1 });
            visit[cur - 1] = true;
            arr[cur - 1] = cur;
        }
        if (cur * 2 < 100001 && !visit[cur * 2]) {
            q.push({ cur * 2, sec + 1 });
            visit[cur * 2] = true;
            arr[cur * 2] = cur;
        }

    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    solve();

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }

    return 0;
}