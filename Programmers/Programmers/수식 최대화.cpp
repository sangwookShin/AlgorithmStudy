#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long cal(long long a, long long b, char oper) {

    if (oper == '*')
        return a * b;
    else if (oper == '+')
        return a + b;
    else if (oper == '-')
        return a - b;
}

long long solution(string expression) {
    long long answer = 0;
    string num = "";
    vector<long long> n;
    vector<char> oper;
    vector<char> oper_list = { '*', '+', '-' };

    for (int i = 0; i < expression.size(); i++) {

        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
            n.push_back(stoi(num));
            num = "";
            oper.push_back(expression[i]);
        }
        else { //숫자 합치기
            num = num + expression[i];
        }
    } //for
    n.push_back(stoi(num));

    do {
        vector<long long> tmp_n = n;
        vector<char> tmp_oper = oper;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < tmp_oper.size(); j++) {

                if (oper_list[i] == tmp_oper[j]) {
                    tmp_n[j] = cal(tmp_n[j], tmp_n[j + 1], oper_list[i]);
                    tmp_n.erase(tmp_n.begin() + j + 1);
                    tmp_oper.erase(tmp_oper.begin() + j);
                    j--;
                } //if 
            } //for j
        } //for i

        answer = max(answer, abs(tmp_n.front()));

    } while (next_permutation(oper_list.begin(), oper_list.end()));

    return answer;
}