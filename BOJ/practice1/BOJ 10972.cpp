#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    if (!next_permutation(v.begin(), v.end())) {
        cout << -1;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
    }

    return 0;
}