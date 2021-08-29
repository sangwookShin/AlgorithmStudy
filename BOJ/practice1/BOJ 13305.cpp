#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long N;
long long dist[100001];
long long price[100001];

void solve() {

    long long max_price = 1000000000;
    long long sum = 0;

    for (int i = 0; i < N - 1; i++) {
        if (max_price > price[i]) {
            max_price = price[i];
        }
        sum = sum + max_price * dist[i];
    }

    cout << sum;
}

int main() {

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> dist[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> price[i];
    }

    solve();

    return 0;
}