#include <string>
#include <vector>
#include <set>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    stack<int> stk;
    set<int> st;
    string answer = "";

    for (int i = 0; i < n; i++) {
        st.insert(i);
        answer += 'X';
    }

    auto cur = st.find(k);

    for (int i = 0; i < cmd.size(); i++) {

        if (cmd[i][0] == 'U' || cmd[i][0] == 'D') {

            int num = stoi(cmd[i].substr(2)); //¼ýÀÚ
            if (cmd[i][0] == 'U') {
                while (num--) {
                    cur = prev(cur);
                }
            } //if
            else {
                while (num--) {
                    cur = next(cur);
                }
            }
        }
        else if (cmd[i][0] == 'C') {
            stk.push(*cur);
            cur = st.erase(cur);
            if (cur == st.end()) {
                cur = prev(cur);
            }
        }
        else if (cmd[i][0] == 'Z') {
            st.insert(stk.top());
            stk.pop();
        } //else if
    } //for

    for (int i : st) {
        answer[i] = 'O';
    }

    return answer;
}