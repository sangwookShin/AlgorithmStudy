#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
pair<int, int> arr[100001];

void solve() {

    sort(arr, arr + N);

    int cnt = 1;
    int interview = arr[0].second;

    for (int i = 1; i < N; i++) {
        if (interview > arr[i].second) {
            cnt++;
            interview = arr[i].second;
        }
    }

    cout << cnt << "\n";

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> arr[j].first >> arr[j].second;
        }

        solve();
    }

    return 0;
}