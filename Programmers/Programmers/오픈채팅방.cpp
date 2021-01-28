#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> user;
    string ID, nickname, state;
    vector<string> UID;

    for (int i = 0; i < record.size(); i++) {

        stringstream ss;
        ss.str(record[i]);
        ss >> state;

        if (state == "Enter") {
            ss >> ID;
            ss >> nickname;
            answer.push_back("´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
            UID.push_back(ID);
            user[ID] = nickname;
        }
        else if (state == "Leave") {
            ss >> ID;
            answer.push_back("´ÔÀÌ ³ª°¬½À´Ï´Ù.");
            UID.push_back(ID);
        }
        else if (state == "Change") {
            ss >> ID;
            ss >> nickname;
            user[ID] = nickname;
        }

        ss.clear();
    }

    for (int i = 0; i < answer.size(); i++) {
        answer[i] = user[UID[i]] + answer[i];
    }

    return answer;
}