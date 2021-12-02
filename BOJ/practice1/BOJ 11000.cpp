#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pair<int, int>> v;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({ s,e });
    }

    sort(v.begin(), v.end());

    pq.push(v[0].second);

    for (int i = 1; i < N; i++) {

        if (pq.top() <= v[i].first) {
            pq.pop();
            pq.push(v[i].second);
        }
        else {
            pq.push(v[i].second);
        }

    }

    cout << pq.size();

    return 0;

}