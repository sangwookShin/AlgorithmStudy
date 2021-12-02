#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    stack<char> s;
    bool check = true;
    int tmp = 1;
    int result = 0;

    cin >> str;

    for (int i = 0; i < str.size(); i++) {

        if (str[i] == '(') {
            tmp *= 2;
            s.push('(');
        }
        else if (str[i] == '[') {
            tmp *= 3;
            s.push('[');
        }
        else if (str[i] == ')' && (s.empty() || s.top() != '(')) {
            check = false;
            break;
        }
        else if (str[i] == ']' && (s.empty() || s.top() != '[')) {
            check = false;
            break;
        }
        else if (str[i] == ')') {

            if (str[i - 1] == '(') {
                result += tmp;
            }
            s.pop();
            tmp /= 2;
        }
        else if (str[i] == ']') {

            if (str[i - 1] == '[') {
                result += tmp;
            }
            s.pop();
            tmp /= 3;
        }

    } //for

    if (check == false || !s.empty()) {
        cout << 0;
    }
    else {
        cout << result;
    }

    return 0;

}