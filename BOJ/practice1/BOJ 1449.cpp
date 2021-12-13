#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[1000];
    int N, L;
    int cnt = 1;
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int pos = arr[0];

    for (int i = 1; i < N; i++) {

        if (arr[i] - pos + 1 > L) {
            cnt++;
            pos = arr[i];
        }
    }
    cout << cnt;

    return 0;
}