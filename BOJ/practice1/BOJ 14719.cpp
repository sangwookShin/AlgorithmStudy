#include <iostream>
#include <algorithm>
using namespace std;

int w, h;
int arr[500];

void solve() {

    int result = 0;

    for (int i = 1; i < w - 1; i++) {
        int left = 0;
        int right = 0;
        for (int j = 0; j < i; j++) {
            left = max(left, arr[j]);
        }
        for (int j = i; j < w; j++) {
            right = max(right, arr[j]);
        }
        result += max(min(left, right) - arr[i], 0);

    }

    cout << result;

    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;

    for (int i = 0; i < w; i++) {
        cin >> arr[i];
    }

    solve();

    return 0;
}