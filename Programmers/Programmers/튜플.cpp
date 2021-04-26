#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> number[500];
    bool visit[100001] = { false, };
    int index = 0;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '{') {
            int j = i + 1;
            string tmp = "";

            while (1) {
                if (s[j] == '}') {
                    break;
                }
                if (s[j] == ',') {
                    number[index].push_back(tmp);
                    tmp = "";
                    j++;
                    continue;
                }
                tmp = tmp + s[j];
                j++;
            } //while

            number[index].push_back(tmp);
            index++;
        } //if
    } //for

    int len = 1;

    while (1) {
        bool flag = false;

        for (int i = 0; i < index; i++) {
            if (number[i].size() == len) { //크기가 작은 배열부터 검사

                flag = true;
                for (int j = 0; j < number[i].size(); j++) {

                    int n = stoi(number[i][j]);
                    if (visit[n] == false) {
                        visit[n] = true;
                        answer.push_back(n);
                    }
                }
                len++;
                break;
            }
        }

        if (flag == false)
            break;
    }//while

    return answer;
}