#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<pair<string, int>> v;

bool comp(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

void findallcourse(string order, int ordersize, string s, int cnt) {

    bool flag = false;

    if (s.length() == ordersize) {
        for (int i = 0; i < v.size(); i++) {
            if (s == v[i].first) {
                v[i].second++;
                flag = true;
            }
        }

        if (flag == false) {
            v.push_back({ s, 1 });
        }

        return;
    }//Á¾·á

    for (int i = cnt; i < order.length(); i++) {
        findallcourse(order, ordersize, s + order[i], i + 1);
    }

}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < course.size(); i++) {

        v.clear();

        for (int j = 0; j < orders.size(); j++) {

            sort(orders[j].begin(), orders[j].end());

            if (orders[j].length() >= course[i]) {
                findallcourse(orders[j], course[i], "", 0);
            }
        } //for

        sort(v.begin(), v.end(), comp);

        if (!v.empty()) {
            int big = v[0].second;

            if (big >= 2) {
                for (int i = 0; i < v.size(); i++) {
                    if (v[i].second == big) {
                        answer.push_back(v[i].first);
                    }
                    else {
                        break;
                    }
                } //for
            } //if
        }

    } //for

    sort(answer.begin(), answer.end());
    return answer;
}