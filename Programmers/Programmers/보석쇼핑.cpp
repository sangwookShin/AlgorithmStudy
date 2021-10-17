#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> g; //전체
    map<string, int> m; //현재 담은 것

    for (int i = 0; i < gems.size(); i++) {
        g.insert(gems[i]);
    }

    int start = 0;
    int end = 0;

    for (int i = 0; i < gems.size(); i++) {
        m[gems[i]]++;
        if (m.size() == g.size()) {
            break;
        }
        end++;
    }

    int dis = end - start;
    answer.push_back(start + 1);
    answer.push_back(end + 1);

    while (end < gems.size()) {

        string s = gems[start];
        m[s]--;
        start++;

        if (m[s] == 0) {

            end++;
            for (; end < gems.size(); end++) {
                m[gems[end]]++;
                if (gems[end] == s) {
                    break;
                }
            }
            if (end == gems.size()) {
                break;
            }
        } //if

        if (dis > end - start) {
            answer[0] = start + 1;
            answer[1] = end + 1;
            dis = end - start;
        } //if

    } //while

    return answer;
}