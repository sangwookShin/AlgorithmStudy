#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;
vector<int> v;
int result[1000001];

void solve() {

    stack<int> s;

    for (int i = N - 1; i >= 0; i--) {

        while (!s.empty() && s.top() <= v[i]) {
            s.pop();
        }

        if (s.empty()) {
            result[i] = -1;
        }
        else {
            result[i] = s.top();
        }

        s.push(v[i]);
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    solve();

    return 0;
}