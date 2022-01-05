#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> st;
    string s;

    getline(cin, s);
    s += '\n';
    bool check = false; // '<' 안에 있는 문자인지 check

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '<') {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << "<";
            check = true;
        }
        else if (s[i] == '>') {
            cout << ">";
            check = false;
        }
        else if (check) {
            cout << s[i];
        }
        else if (s[i] == ' ' || s[i] == '\n') {
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << " ";
        }
        else {
            st.push(s[i]);
        } //else

    } //for

    return 0;
}