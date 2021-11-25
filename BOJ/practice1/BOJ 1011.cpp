#include <iostream>

using namespace std;

void solve(double x, double y) {

    double i = 1;
    double result;

    for (;; i++) {
        if (y - x < i * i) {
            break;
        }
    }

    if (y - x == (i - 1) * (i - 1)) {
        result = 2 * (i - 1) - 1;
    }
    else if (y - x < ((i - 1) * (i - 1) + (i * i)) / 2) {
        result = (i - 1) * 2;
    }
    else {
        result = 2 * i - 1;
    }

    cout << result << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++) {
        double x, y;
        cin >> x >> y;
        solve(x, y);
    }

    return 0;
}