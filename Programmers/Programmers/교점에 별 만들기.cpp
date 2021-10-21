#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<long long, long long>> v; //교점 저장

    long long min_x = LLONG_MAX;
    long long min_y = LLONG_MAX;
    long long max_x = LLONG_MIN;
    long long max_y = LLONG_MIN;

    for (int i = 0; i < line.size(); i++) {

        for (int j = i + 1; j < line.size(); j++) {

            long long A = line[i][0];
            long long B = line[i][1];
            long long E = line[i][2];
            long long C = line[j][0];
            long long D = line[j][1];
            long long F = line[j][2];
            long long x, y; //교점
            if (A * D - B * C == 0) {
                continue;
            }
            if ((B * F - E * D) % (A * D - B * C) || (E * C - A * F) % (A * D - B * C)) {
                continue;
            }
            x = (B * F - E * D) / (A * D - B * C);
            y = (E * C - A * F) / (A * D - B * C);

            min_x = min(min_x, x);
            min_y = min(min_y, y);
            max_x = max(max_x, x);
            max_y = max(max_y, y);

            v.push_back({ x,y });
        } //for  
    }//for

    for (int i = 0; i <= max_y - min_y; i++) {
        string tmp = "";
        for (int j = 0; j <= max_x - min_x; j++) {
            tmp += ".";
        }
        answer.push_back(tmp);
    }

    for (int i = 0; i < v.size(); i++) {
        int x = abs(v[i].first - min_x);
        int y = abs(v[i].second - max_y);
        answer[y][x] = '*';
    }

    return answer;
}