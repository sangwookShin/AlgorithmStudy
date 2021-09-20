#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

long long n, q;

void solve() {

    q = sqrt(n);

    if (q * q < n) {
        q++;
    }

    cout << q;

}

int main() {

    cin >> n;

    solve();

    return 0;
}