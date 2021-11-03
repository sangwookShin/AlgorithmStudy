#include <iostream>
#include <vector>

using namespace std;

int N, M;
string s;

void solve() {

    int cnt;
    int result = 0;

    for (int i = 0; i < M; i++) {

        cnt = 0;

        if (s[i] == 'I') {

            while (s[i + 1] == 'O' && s[i + 2] == 'I') {

                i += 2;
                cnt++;
                if (cnt == N) {
                    result++; cnt--;
                }
            } //while
        } //if
    }//for

    cout << result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> s;

    solve();

    return 0;
}