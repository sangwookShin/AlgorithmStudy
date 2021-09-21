#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[1000000];

bool possibility(int m) {

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        cnt = cnt + (arr[i] / m);
    }

    if (cnt < M) {
        return false;
    }

    return true;
}

void solve() {

    int low = 1;
    int high = 0;
    int result = 0;

    for (int i = 0; i < N; i++) {
        high = max(high, arr[i]);
    }

    while (low <= high) {

        int mid = (low + high) / 2;

        if (possibility(mid)) {
            result = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << result;
}

int main() {

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    solve();

    return 0;
}