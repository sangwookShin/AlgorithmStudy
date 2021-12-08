#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int arr[101];
    int cnt[101];
    cin >> N >> M;

    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }

    memset(cnt, -1, sizeof(cnt));
    cnt[1] = 0;
    queue<int> q;
    q.push(1);


    while (!q.empty()) {

        int x = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {

            int nx = x + i;
            if (nx > 100) {
                continue;
            }

            if (arr[nx] != 0) {
                nx = arr[nx];
            }

            if (cnt[nx] == -1) {
                cnt[nx] = cnt[x] + 1;
                q.push(nx);
            }
        } //for
    } //while

    cout << cnt[100];

    return 0;

}