#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[11][11];
bool visit[11];
int result = 987654321;
int end_node;

void DFS(int start, int cnt, int sum) {

    if (cnt == N - 1) {

        if (arr[start][end_node]) {
            result = min(result, sum + arr[start][end_node]);
        }
        return;
    }

    for (int i = 0; i < N; i++) {

        if (arr[start][i] != 0 && visit[i] == false) {
            visit[i] = true;
            DFS(i, cnt + 1, sum + arr[start][i]);
            visit[i] = false;
        }
    } //for
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        end_node = i;
        visit[i] = true;
        DFS(i, 0, 0);
        visit[i] = false;
    }

    cout << result;

    return 0;
}