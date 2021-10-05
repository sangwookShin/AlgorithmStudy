#include <iostream>
#include <algorithm>
#include <deque>;
#include <string>
using namespace std;

int T;
deque<int> dq;
int k;
string tmp;
bool re = false; //거꾸로인지 아닌지 체크

void solve() {

    for (int i = 0; i < tmp.size(); i++) {

        if (tmp[i] == 'R') {
            if (re == false) { //거꾸로 바꿔주기
                re = true;
            }
            else if (re == true) { //거꾸로 x
                re = false;
            }
        }
        else if (tmp[i] == 'D') {
            if (dq.size() == 0) {
                cout << "error" << "\n";
                return;
            }
            else {
                if (re == true) { //거꾸로
                    dq.pop_back();
                }
                else if (re == false) { //거꾸로x
                    dq.pop_front();
                }

            }
        }//else if

    }//for

    if (re == true) {
        cout << "[";
        for (int i = dq.size() - 1; i >= 0; i--) {
            cout << dq[i];
            if (i != 0) {
                cout << ",";
            }
        }
        cout << "]" << "\n";
    }
    else {
        cout << "[";
        for (int i = 0; i < dq.size(); i++) {
            cout << dq[i];
            if (i != dq.size() - 1) {
                cout << ",";
            }
        }
        cout << "]" << "\n";
    }

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        tmp = ""; //수행할 함수
        string p; //배열
        string a = "";
        re = false;
        int n;
        dq.clear();
        cin >> tmp >> n >> p;

        for (int j = 0; j < p.size(); j++) {
            if (p[j] == '[') {
                continue;
            }
            else if ('0' <= p[j] && p[j] <= '9') {
                a += p[j];
            }
            else if (p[j] == ',' || p[j] == ']') {
                if (a != "") {
                    dq.push_back(stoi(a));
                    a = "";
                }
            }
        }

        solve();
    }

    return 0;
}