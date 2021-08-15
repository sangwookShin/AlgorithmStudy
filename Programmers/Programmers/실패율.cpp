#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<double, int>& a, pair<double, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int clearstage[501] = { 0, };
    int nonclearstage[501] = { 0, };
    vector<pair<double, int>> v;

    for (int i = 0; i < stages.size(); i++) {
        int t;
        t = stages[i];

        //클리어 한 단계 카운트
        for (int j = 1; j < t; j++) {
            clearstage[j]++;
        }

        //클리어 못한 단계 카운트
        nonclearstage[t]++;
    }

    for (int i = 1; i <= N; i++) {
        if (clearstage[i] == 0 && nonclearstage[i] == 0) {
            v.push_back({ 0, i });
        }
        else {
            v.push_back({ (double)nonclearstage[i] / (double)(clearstage[i] + nonclearstage[i]), i });
        }
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++) {
        answer.push_back(v[i].second);
    }

    return answer;
}