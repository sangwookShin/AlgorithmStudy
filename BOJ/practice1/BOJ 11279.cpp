#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
void solve() {

    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {

        int a;
        cin >> a;
        if (a == 0) {
            if (pq.empty()) {
                cout << "0" << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(a);
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    solve();

    return 0;
}