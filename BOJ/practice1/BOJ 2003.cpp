#include <iostream>
#include <algorithm>

using namespace std;

long long N, M;
long long arr[10001];

void solve() {

    long long sum = 0;
    long long cnt = 0;
    long long left = 0;
    long long right = 0;

    while (left <= right && right <= N) {

        if (sum >= M) {
            if (sum == M) {
                cnt++;
            }
            sum = sum - arr[left];
            left++;
        }
        else {
            if (right == N) {
                break;
            }
            sum = sum + arr[right];
            right++;
        }
    }

    cout << cnt;

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    solve();

    return 0;
}