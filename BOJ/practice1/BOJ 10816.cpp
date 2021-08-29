#include <iostream>
#include <algorithm>

using namespace std;

long long N, M;
long long card[500001];
long long test[500001];

void solve() {

    sort(card, card + N);

    for (int i = 0; i < M; i++) {
        cout << upper_bound(card, card + N, test[i]) - lower_bound(card, card + N, test[i]) << "\n";
    }
}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> card[i];
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> test[i];
    }

    solve();

    return 0;
}