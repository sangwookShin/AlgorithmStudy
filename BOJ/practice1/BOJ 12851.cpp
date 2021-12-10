#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;

void solve() {

    int cnt = 0;
    int result = 0;
    bool visit[100001] = { false, };

    queue<pair<int, int>> q;
    q.push({ N, 0 });


    while (!q.empty()) {

        int x = q.front().first;
        int sec = q.front().second;
        q.pop();
        visit[x] = true;

        if (result != 0 && result == sec && K == x) { //�ߺ��ؼ� ��� �����Ҷ����� cnt ������
            cnt++;
        }

        if (result == 0 && x == K) { //��ó�� �������� ��, result ���� ������
            cnt++;
            result = sec;
        }

        if (x + 1 < 100001 && !visit[x + 1]) {
            q.push({ x + 1, sec + 1 });
        }
        if (x - 1 >= 0 && !visit[x - 1]) {
            q.push({ x - 1, sec + 1 });
        }
        if (x * 2 < 100001 && !visit[x * 2]) {
            q.push({ x * 2, sec + 1 });
        }

    } //while

    cout << result << "\n" << cnt;
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    solve();

    return 0;
}