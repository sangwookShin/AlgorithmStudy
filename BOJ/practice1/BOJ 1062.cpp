#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int sum = 0;
vector<string> words;
bool able[26];

int Read() {

    bool can;
    int cnt = 0;

    for (int i = 0; i < words.size(); i++) {

        can = true;

        for (int j = 0; j < words[i].size(); j++) {

            if (able[words[i][j] - 'a'] == false) {
                can = false;
                break;
            }
        }

        if (can == true) {
            cnt++;
        }
    }

    return cnt;
}

void DFS(int index, int cnt) {

    if (cnt == K) {
        sum = max(sum, Read());
        return;
    }

    for (int i = index; i < 26; i++) {

        if (able[i] == true) {
            continue;
        }

        able[i] = true;
        DFS(i, cnt + 1);
        able[i] = false;
    }
}

void solve() {

    if (K < 5) {
        return;
    }

    K = K - 5;
    DFS(0, 0);
}

int main() {

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        words.push_back(tmp);
    }

    able['a' - 'a'] = true;
    able['n' - 'a'] = true;
    able['t' - 'a'] = true;
    able['i' - 'a'] = true;
    able['c' - 'a'] = true;

    solve();

    cout << sum;

    return 0;
}