#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int A[51];
int B[51];

void solve() {

    int result = 0;

    sort(A, A + N);
    sort(B, B + N, greater<>());

    for (int i = 0; i < N; i++) {
        result = result + (A[i] * B[i]);
    }

    cout << result;

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    solve();

    return 0;
}