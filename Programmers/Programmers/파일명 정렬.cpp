#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<pair<string, int>, pair<string, int>> a, pair<pair<string, int>, pair<string, int>> b) {

    if (a.first.first == b.first.first) { //HEAD가 같다.
        if (a.first.second == b.first.second) { //NUMBER가 같다.
            return a.second.second < b.second.second;
        }
        return a.first.second < b.first.second;
    }
    else {
        return a.first.first < b.first.first;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<pair<string, int>, pair<string, int>>> file_tmp; //HEAD, NUMBER, 원래값, 위치

    for (int i = 0; i < files.size(); i++) { //전체
        string head = "";
        string number = "";
        int j = 0;
        int cnt = 0;
        int n;

        while (1) { //HEAD
            if (files[i][j] >= '0' && files[i][j] <= '9') {
                break;
            }
            head += tolower(files[i][j]);
            j++;
        }

        while (files[i][j] >= '0' && files[i][j] <= '9' && cnt < 5) { //NUMBER
            number += files[i][j];
            cnt++;
            j++;
        }

        n = stoi(number);
        file_tmp.push_back({ {head, n}, {files[i], i} });
    } //for

    stable_sort(file_tmp.begin(), file_tmp.end(), cmp);

    for (int i = 0; i < file_tmp.size(); i++) {
        answer.push_back(file_tmp[i].second.first);
    }

    return answer;
}