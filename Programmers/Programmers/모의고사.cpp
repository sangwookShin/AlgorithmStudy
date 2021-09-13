#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;

    for (int i = 0; i < answers.size(); i++) { //수포자1

        if (i % 5 == 0 && answers[i] == 1) {
            cnt1++;
        }
        else if (i % 5 == 1 && answers[i] == 2) {
            cnt1++;
        }
        else if (i % 5 == 2 && answers[i] == 3) {
            cnt1++;
        }
        else if (i % 5 == 3 && answers[i] == 4) {
            cnt1++;
        }
        else if (i % 5 == 4 && answers[i] == 5) {
            cnt1++;
        }
    }

    for (int i = 0; i < answers.size(); i++) { //수포자2

        if (i % 8 == 0 && answers[i] == 2) {
            cnt2++;
        }
        else if (i % 8 == 1 && answers[i] == 1) {
            cnt2++;
        }
        else if (i % 8 == 2 && answers[i] == 2) {
            cnt2++;
        }
        else if (i % 8 == 3 && answers[i] == 3) {
            cnt2++;
        }
        else if (i % 8 == 4 && answers[i] == 2) {
            cnt2++;
        }
        else if (i % 8 == 5 && answers[i] == 4) {
            cnt2++;
        }
        else if (i % 8 == 6 && answers[i] == 2) {
            cnt2++;
        }
        else if (i % 8 == 7 && answers[i] == 5) {
            cnt2++;
        }
    }

    for (int i = 0; i < answers.size(); i++) { //수포자3

        if (i % 10 == 0 && answers[i] == 3) {
            cnt3++;
        }
        else if (i % 10 == 1 && answers[i] == 3) {
            cnt3++;
        }
        else if (i % 10 == 2 && answers[i] == 1) {
            cnt3++;
        }
        else if (i % 10 == 3 && answers[i] == 1) {
            cnt3++;
        }
        else if (i % 10 == 4 && answers[i] == 2) {
            cnt3++;
        }
        else if (i % 10 == 5 && answers[i] == 2) {
            cnt3++;
        }
        else if (i % 10 == 6 && answers[i] == 4) {
            cnt3++;
        }
        else if (i % 10 == 7 && answers[i] == 4) {
            cnt3++;
        }
        else if (i % 10 == 8 && answers[i] == 5) {
            cnt3++;
        }
        else if (i % 10 == 9 && answers[i] == 5) {
            cnt3++;
        }
    }

    int n = max(cnt1, max(cnt2, cnt3));

    if (n == cnt1) {
        answer.push_back(1);
    }
    if (n == cnt2) {
        answer.push_back(2);
    }
    if (n == cnt3) {
        answer.push_back(3);
    }

    return answer;
}