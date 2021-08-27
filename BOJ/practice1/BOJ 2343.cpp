#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int sum = 0;
long long blueray[100001];

bool check(int mid) {

    int cnt = 0;
    int num = 1;

    for (int i = 0; i < N; i++) {

        if (blueray[i] > mid) {
            return false;
        }

        cnt = cnt + blueray[i];
        if (cnt > mid) {
            cnt = blueray[i];
            num++;
        }
    }

    return M >= num;
}

void solve() {

    long long low = 1;
    long long high = sum;
    long long result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (check(mid) == true) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << result;
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> blueray[i];
        sum = sum + blueray[i];
    }

    solve();

    return 0;
}