#include <iostream>

using namespace std;

int N, M;
int arr[9];

void DFS(int n, int cnt) {

    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = n; i <= N; i++) {
        arr[cnt] = i;
        DFS(i, cnt + 1);
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    DFS(1, 0);

    return 0;
}