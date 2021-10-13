#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr[3][2][2][2];

vector<int> split_info(string s) {

    vector<int> result;
    string tmp = "";

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == ' ') {
            if (tmp == "cpp" || tmp == "backend" || tmp == "junior" || tmp == "chicken") {
                result.push_back(0);
                tmp = "";
            } //if
            else if (tmp == "java" || tmp == "frontend" || tmp == "senior" || tmp == "pizza") {
                result.push_back(1);
                tmp = "";
            } //else if
            else if (tmp == "python") {
                result.push_back(2);
                tmp = "";
            } //else if
        } // if
        else {
            tmp += s[i];
        } //else
    } //for

    result.push_back(stoi(tmp));
    return result;
}

vector<string> split_query(string s) {

    vector<string> result;
    string tmp = "";

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            result.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += s[i];
        }
    } //for

    result.push_back(tmp);
    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (int i = 0; i < info.size(); i++) { //info 종류 별로 저장
        vector<int> a = split_info(info[i]);
        arr[a[0]][a[1]][a[2]][a[3]].push_back(a[4]);
    } //for

    for (int i = 0; i < 3; i++) { //이분탐색을 위한 정렬
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    sort(arr[i][j][k][l].begin(), arr[i][j][k][l].end());
                }
            }
        }
    } //for

    for (int i = 0; i < query.size(); i++) { //쿼리 실행

        vector<string> v = split_query(query[i]);

        int score = stoi(v[7]); //점수

        int ai, aj, ak, al;
        int bi, bj, bk, bl;
        if (v[0] == "cpp") { //언어
            ai = 0; bi = 0;
        }
        else if (v[0] == "java") {
            ai = 1; bi = 1;
        }
        else if (v[0] == "python") {
            ai = 2; bi = 2;
        }
        else {
            ai = 0; bi = 2;
        }

        if (v[2] == "backend") { //직군
            aj = 0; bj = 0;
        }
        else if (v[2] == "frontend") {
            aj = 1; bj = 1;
        }
        else {
            aj = 0; bj = 1;
        }

        if (v[4] == "junior") { //경력
            ak = 0; bk = 0;
        }
        else if (v[4] == "senior") {
            ak = 1; bk = 1;
        }
        else {
            ak = 0; bk = 1;
        }

        if (v[6] == "chicken") { //소울푸드
            al = 0; bl = 0;
        }
        else if (v[6] == "pizza") {
            al = 1; bl = 1;
        }
        else {
            al = 0; bl = 1;
        }

        int result = 0;

        for (int j = ai; j <= bi; j++) {
            for (int k = aj; k <= bj; k++) {
                for (int l = ak; l <= bk; l++) {
                    for (int m = al; m <= bl; m++) {

                        if (arr[j][k][l][m].size() == 0) {
                            continue;
                        }

                        auto iter = lower_bound(arr[j][k][l][m].begin(), arr[j][k][l][m].end(), score);

                        if (iter == arr[j][k][l][m].end()) {
                            continue;
                        }

                        result += arr[j][k][l][m].size() - (iter - arr[j][k][l][m].begin());

                    }
                }
            }
        }

        answer.push_back(result);
    } //for


    return answer;
}