#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int min_num = 987654321;
int max_num = 0;

int check(string s) { //s에서 홀수 개수를 구한다

    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] - '0') % 2 == 1) { //홀수라면
            cnt++;
        }
    }

    return cnt;
}

void solve(string s, int total_cnt) {

    if (s.size() == 1) {

        total_cnt += check(s);
        min_num = min(min_num, total_cnt);
        max_num = max(max_num, total_cnt);
        return;
    }
    else if (s.size() == 2) {

        string s1(1, s[0]);
        string s2(1, s[1]);

        string sum_s = to_string((s[0] - '0') + (s[1] - '0'));
        int sum_s1_s2 = check(s1) + check(s2);
        solve(sum_s, total_cnt + sum_s1_s2);
    }
    else if (s.size() >= 3) {

        vector<bool> com(s.size() - 1, false);

        com[0] = true;
        com[1] = true;

        do {
            vector<int> v;

            for (int i = 0; i < s.size() - 1; i++) {
                if (com[i]) {
                    v.push_back(i);
                }
            } //for

            string s1 = s.substr(0, v[0] + 1);
            string s2 = s.substr(v[0] + 1, v[1] - v[0]);
            string s3 = s.substr(v[1] + 1, s.size() - 1 - v[1]);

            string next = to_string(stoi(s1) + stoi(s2) + stoi(s3));
            int sum_s1_s2_s3 = check(s1) + check(s2) + check(s3);
            solve(next, total_cnt + sum_s1_s2_s3);

        } while (prev_permutation(com.begin(), com.end()));


    } //else if


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N;

    cin >> N;

    solve(N, 0);

    cout << min_num << " " << max_num;

    return 0;
}