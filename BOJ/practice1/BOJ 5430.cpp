#include <iostream>
#include <algorithm>
#include <deque>;
#include <string>
using namespace std;

int T;
deque<int> dq;
int k;
string tmp;
bool re = false; //�Ųٷ����� �ƴ��� üũ

void solve() {

    for (int i = 0; i < tmp.size(); i++) {

        if (tmp[i] == 'R') {
            if (re == false) { //�Ųٷ� �ٲ��ֱ�
                re = true;
            }
            else if (re == true) { //�Ųٷ� x
                re = false;
            }
        }
        else if (tmp[i] == 'D') {
            if (dq.size() == 0) {
                cout << "error" << "\n";
                return;
            }
            else {
                if (re == true) { //�Ųٷ�
                    dq.pop_back();
                }
                else if (re == false) { //�Ųٷ�x
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
        tmp = ""; //������ �Լ�
        string p; //�迭
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