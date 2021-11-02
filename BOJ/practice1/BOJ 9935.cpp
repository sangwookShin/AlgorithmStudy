#include <iostream>
#include <vector>

using namespace std;

string s, bomb;

void solve() {

    vector<char> answer;

    for (int i = 0; i < s.length(); i++) {

        answer.push_back(s[i]);
        if (answer.size() < bomb.size()) {
            continue;
        }
        if (answer[answer.size() - 1] == bomb[bomb.size() - 1]) {
            bool check = true;
            for (int j = 2; j <= bomb.size(); j++) {
                if (answer[answer.size() - j] != bomb[bomb.size() - j]) {
                    check = false;
                } //if
            }
            if (check == true) {
                answer.erase(answer.end() - bomb.size(), answer.end());
            }
        } //if

    } //for

    if (answer.size() == 0) {
        cout << "FRULA";
        return;
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> bomb;

    solve();

    return 0;
}