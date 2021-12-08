#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
string arr[300000];

void solve() {

    queue<int> q[21]; //���� ���̸� ���� ť���� ����, ex) q[3]�� ���̰� 3�� �͵��� ��� ����
    long long result = 0;

    for (int i = 0; i < N; i++) {

        int len = arr[i].length();
        while (!q[len].empty() && abs(i - q[len].front()) > K) { //ť�� �Ⱥ������ ���̰� K���� ū�͵��� ���Ѵ�.
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