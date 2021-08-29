#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

void solve() {

    int result = 0;

    while (pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        result = result + a + b;

        pq.push(a + b);
    }

    cout << result;
}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    solve();

    return 0;
}