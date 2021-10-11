#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> save; //나온 단어 저장
    int turn = 1; //턴 수
    char last_word = words[0][words[0].size() - 1];
    char first_word;

    //첫 단어 저장
    save.push_back(words[0]);

    for (int i = 1; i < words.size(); i++) {

        if ((i + 1) % n == 1) {
            turn++;
        }

        //끝단어 시작단어 체크
        first_word = words[i][0];

        if (last_word != first_word) {
            int num = (i + 1) % n;
            if (num == 0) {
                num = n;
            }
            answer.push_back(num);
            answer.push_back(turn);
            return answer;
        }
        //마지막 단어 끝 설정
        last_word = words[i][words[i].size() - 1];

        //중복된 단어 체크
        if (find(save.begin(), save.end(), words[i]) != save.end()) { //중복된게 있음
            int num = (i + 1) % n;
            if (num == 0) {
                num = n;
            }
            answer.push_back(num);
            answer.push_back(turn);
            return answer;
        }

        //단어 저장
        save.push_back(words[i]);
    }

    answer.push_back(0);
    answer.push_back(0);

    return answer;
}