#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int cnt = 0; //������ 0�� ����
    int turn = 0; //��ȯ Ƚ��
    int a;
    answer.push_back(0);
    answer.push_back(0);

    while (s != "1") {

        string tmp = "";
        turn++;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                cnt++;
            }
            else {
                tmp += s[i];
            }
        } //for

        a = tmp.size();
        s = "";

        while (a > 0) {
            s += to_string(a % 2);
            a /= 2;
        }

    } //while

    answer[0] = turn;
    answer[1] = cnt;

    return answer;
}