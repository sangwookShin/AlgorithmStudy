#include <iostream>
#include <algorithm>

using namespace std;

int arr[13];
int result[6];
int k;

void solve(int s, int cnt) {

    if (cnt == 6) {
        for (int i = 0; i < 6; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = s; i < k; i++) {
        result[cnt] = arr[i];
        solve(i + 1, cnt + 1);
    }

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {

        cin >> k;
        if (k == 0) {
            break;
        }

        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        solve(0, 0);
        cout << "\n";
    }

    return 0;
}