#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;

    int N;

    cin >> N;

    for (int i = 0; i < N * N; i++) {
        int a;
        cin >> a;
        pq.push(a);
        if (pq.size() > N) {
            pq.pop();
        }
    }

    cout << pq.top();

    return 0;

}