#include <string>
#include <vector>
#include <cctype>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    double intersection = 0; //교집합
    double Union = 0; //합집합

    vector<string> s1; //str1 2개씩 모은 벡터
    vector<string> s2; //str2 2개씩 모은 벡터

    if (str1.length() == 0 || str2.length() == 0) {
        return 65536;
    }

    for (int i = 0; i < str1.length(); i++) {
        str1[i] = tolower(str1[i]);
    }
    for (int i = 0; i < str2.length(); i++) {
        str2[i] = tolower(str2[i]);
    }

    for (int i = 0; i <= str1.length() - 2; i++) { //str1
        if (('a' <= str1[i] && str1[i] <= 'z') && ('a' <= str1[i + 1] && str1[i + 1] <= 'z')) {
            s1.push_back(str1.substr(i, 2));
        }
    }

    for (int i = 0; i <= str2.length() - 2; i++) { //str2
        if (('a' <= str2[i] && str2[i] <= 'z') && ('a' <= str2[i + 1] && str2[i + 1] <= 'z')) {
            s2.push_back(str2.substr(i, 2));
        }
    }

    //교집합 구하기
    for (int i = 0; i < s2.size(); i++) {
        for (int j = 0; j < s1.size(); j++) {
            if (s1[j] == s2[i]) {
                intersection++;
                s1[j] = '%';
                break;
            }
        }
    }

    Union = s1.size() + s2.size() - intersection;

    if (Union == 0) {
        return 65536;
    }

    answer = 65536 * intersection / Union;
    return answer;
}