#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

void solve() {

    sort(v.begin(), v.end());

    int start = 0;
    int end = N - 1;
    int result = 2000000000;
    int x, y;

    while (start < end) {

        int sum = v[start] + v[end];

        if (result > abs(sum)) {
            result = abs(sum);
            x = v[start];
            y = v[end];

            if (sum == 0) {
                break;
            }
        }

        if (sum < 0) {
            start++;
        }
        else {
            end--;
        }

    } //while

    cout << x << " " << y;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    solve();

    return 0;
}