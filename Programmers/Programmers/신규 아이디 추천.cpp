#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    //1�ܰ�
    for (int i = 0; i < new_id.size(); i++) {
        if ('A' <= new_id[i] && new_id[i] <= 'Z') {
            new_id[i] = tolower(new_id[i]);
        }
    }

    //2�ܰ�
    for (int i = 0; i < new_id.size(); i++) {
        if (('a' <= new_id[i] && new_id[i] <= 'z') || ('0' <= new_id[i] && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            answer.push_back(new_id[i]);
        }
    }

    //3�ܰ�
    string tmp = "";
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] == '.') {
            tmp.push_back(answer[i]);
            while (answer[i] == '.') {
                i++;
            }
            i--;
        }
        else {
            tmp.push_back(answer[i]);
        }
    }

    answer = "";
    answer = tmp;

    //4�ܰ�
    if (answer[0] == '.') {
        answer = answer.substr(1);
    }
    if (answer[answer.size() - 1] == '.') {
        answer = answer.substr(0, answer.size() - 1);
    }

    //5�ܰ�
    if (answer.size() == 0) {
        answer = 'a';
    }

    //6�ܰ�
    if (answer.size() >= 16) {
        answer = answer.substr(0, 15);
    }
    if (answer[answer.size() - 1] == '.') {
        answer = answer.substr(0, answer.size() - 1);
    }

    //7�ܰ�
    if (answer.size() <= 2) {
        while (answer.size() != 3) {
            answer = answer + answer[answer.size() - 1];
        }
    }

    return answer;
}