#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(char c, int dis, int cur_dis) {

    if (c == '=') {
        return dis == cur_dis;
    }
    else if (c == '<') {
        return dis > cur_dis;
    }
    else if (c == '>') {
        return dis < cur_dis;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";

    do {
        bool ok = true;
        for (int i = 0; i < data.size(); i++) {

            int dis = data[i][4] - '0';
            char a = data[i][0]; //1친구
            char b = data[i][2]; //2친구
            char c = data[i][3]; //부등호
            int cur_dis = abs((int)(friends.find(a) - friends.find(b))) - 1;
            if (check(c, dis, cur_dis) == false) {
                ok = false;
                break;
            }
        } //for

        if (ok == true) {
            answer++;
        }

    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}