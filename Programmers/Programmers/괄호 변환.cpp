#include <string>
#include <vector>

using namespace std;

bool isRight(string s) { //올바른 괄호 문자열인지 판별

    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {

        if (s[i] == '(') {
            cnt++;
        }
        else {
            cnt--;
        }

        if (cnt < 0) {
            return false;
        }
    } //for
    return true;
}

string solution(string p) {
    if (p.length() == 0) {
        return "";
    }
    string answer = "";
    string u = "";
    string v = "";
    int cnt = 0;

    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') {
            cnt++;
        }
        else {
            cnt--;
        }

        if (cnt == 0) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (isRight(u) == true) { //u가 올바른 괄호 문자열
        answer = answer + u;
        answer = answer + solution(v);
        return answer;
    }
    else { //u가 올바른 괄호 문자열 x
        string tmp = "(";
        tmp = tmp + solution(v);
        tmp = tmp + ")";
        u = u.substr(1, u.length() - 2);
        for (int i = 0; i < u.length(); i++) {
            if (u[i] == '(') {
                tmp = tmp + ')';
            }
            else {
                tmp = tmp + '(';
            }
        }

        return tmp;
    }


    return answer;
}