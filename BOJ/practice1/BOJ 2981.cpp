#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int arr[101];
int N;

int GCD(int a, int b) {

    if (a % b == 0) {
        return b;
    }

    return GCD(b, a % b);
}

void solve() {

    sort(arr, arr + N);

    set<int> s;

    int gcd = arr[1] - arr[0];

    for (int i = 2; i < N; i++) {
        gcd = GCD(gcd, arr[i] - arr[i - 1]);
    }

    for (int i = 2; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            s.insert(i);
            s.insert(gcd / i);
        }
    }

    s.insert(gcd);

    set<int>::iterator iter;

    for (iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << " ";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    solve();

    return 0;
}