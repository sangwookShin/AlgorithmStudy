#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int nagudo[8];
int weight[8];
int result;

void DFS(int idx) {

    if (idx >= n) {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nagudo[i] <= 0) {
                cnt++;
            }
        }
        result = max(result, cnt);
        return;
    } //if

    if (nagudo[idx] <= 0) { //깨졌으면 다음 계란으로 이동
        DFS(idx + 1);
    }
    else {
        bool check = false;
        for (int i = 0; i < n; i++) {
            if (i == idx || nagudo[i] <= 0) {
                continue;
            }

            nagudo[idx] = nagudo[idx] - weight[i];
            nagudo[i] = nagudo[i] - weight[idx];

            check = true;
            DFS(idx + 1);
            nagudo[idx] = nagudo[idx] + weight[i];
            nagudo[i] = nagudo[i] + weight[idx];

        }
        if (!check) {
            DFS(n);
        }
    } //else


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> nagudo[i] >> weight[i];
    }

    DFS(0);

    cout << result;

    return 0;
}