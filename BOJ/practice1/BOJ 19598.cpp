#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int cnt = 0;
    int result = 0;
    vector<pair<int, int>> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,1 });
        v.push_back({ b,-1 });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cnt += v[i].second;
        result = max(cnt, result);
    }
    cout << result;
    return 0;
}