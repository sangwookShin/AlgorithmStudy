#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> num;

    for (int i = 0; i < dartResult.length(); i++) {

        if ('0' <= dartResult[i] && dartResult[i] <= '9') {//숫자
            if (dartResult[i] == '1' && dartResult[i + 1] == '0') { //10점
                num.push_back(10);
                i++;
                continue;
            }
            else {
                int n = dartResult[i] - '0';
                num.push_back(n);
                continue;
            }
        } // 숫자 if

        if (dartResult[i] == 'S') {
            continue;
        }
        else if (dartResult[i] == 'D') {
            num[num.size() - 1] = num[num.size() - 1] * num[num.size() - 1];
        }
        else if (dartResult[i] == 'T') {
            num[num.size() - 1] = num[num.size() - 1] * num[num.size() - 1] * num[num.size() - 1];
        }

        if (dartResult[i] == '*') {
            if (num.size() > 1) {
                num[num.size() - 1] = num[num.size() - 1] * 2;
                num[num.size() - 2] = num[num.size() - 2] * 2;
            }
            else {
                num[num.size() - 1] = num[num.size() - 1] * 2;
            }
        }
        else if (dartResult[i] == '#') {
            num[num.size() - 1] = num[num.size() - 1] * (-1);
        }
    } //for

    for (int i = 0; i < num.size(); i++) {
        answer = answer + num[i];
    }

    return answer;
}