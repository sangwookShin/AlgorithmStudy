#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
string arr[300000];

void solve() {

    queue<int> q[21]; //같은 길이를 가진 큐끼리 모음, ex) q[3]은 길이가 3인 것들의 등수 저장
    long long result = 0;

    for (int i = 0; i < N; i++) {

        int len = arr[i].length();
        while (!q[len].empty() && abs(i - q[len].front()) > K) { //큐가 안비었을때 차이가 K보다 큰것들은 팝한다.
            q[len].pop();
        } //while
        result += q[len].size();
        q[len].push(i);
    }

    cout << result;
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    solve();

    return 0;

}