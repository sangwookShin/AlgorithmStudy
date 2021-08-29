#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if (cacheSize == 0) {
        return cities.size() * 5;
    }

    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].size(); j++) {
            cities[i][j] = tolower(cities[i][j]);
        }
    }

    for (int i = 0; i < cities.size(); i++) {

        bool flag = false;

        //있으면 hit
        for (int j = 0; j < v.size(); j++) {
            if (cities[i] == v[j]) {
                v.erase(v.begin() + j);
                v.push_back(cities[i]);
                flag = true;
                answer++;
                break;
            }
        }
        //없으면 miss
        if (flag == false) {
            answer += 5;

            if (v.size() >= cacheSize) {
                v.erase(v.begin());
            }
            v.push_back(cities[i]);
        }
    }

    return answer;
}