#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, k;

    cin >> N >> k;

    int low = 1;
    int high = k;
    int result;

    while (low <= high) {

        int mid = (low + high) / 2;
        int cnt = 0;

        for (int i = 1; i <= N; i++) {
            cnt += min(mid / i, N);
        }

        if (cnt < k) {
            low = mid + 1;
        }
        else {
            result = mid;
            high = mid - 1;
        }
    }

    cout << result;
    return 0;

}