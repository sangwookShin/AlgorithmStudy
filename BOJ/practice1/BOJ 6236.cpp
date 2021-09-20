#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100001];

bool possibility(int m) {

    int cnt = 1;
    int sum = m;

    for (int i = 0; i < N; i++) {

        if (m < arr[i]) {
            return false;
        }

        if (sum - arr[i] < 0) {
            sum = m;
            cnt++;
        }

        sum = sum - arr[i];
    }

    return M >= cnt;
}

void solve() {

    int k;
    int low = 0;
    int high = 0;

    for (int i = 0; i < N; i++) {
        high += arr[i];
    }

    while (low <= high) {

        int mid = (low + high) / 2;

        if (possibility(mid)) {
            k = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << k;
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    solve();

    return 0;
}