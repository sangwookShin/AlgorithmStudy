#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;

    for (int j = 0; j < s.size(); j++) {

        stack<int> st;
        bool check = true;
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
                check = false;
            }
            else {
                if (st.top() == '(' && s[i] == ')') {
                    st.pop();
                }
                else if (st.top() == '{' && s[i] == '}') {
                    st.pop();
                }
                else if (st.top() == '[' && s[i] == ']') {
                    st.pop();
                }
            }
        } //for

        if (st.empty() && check == false) {
            answer++;
        }

        char c = s[0];
        for (int k = 0; k < s.size() - 1; k++) {
            s[k] = s[k + 1];
        }
        s[s.size() - 1] = c;

    } //for

    return answer;
}