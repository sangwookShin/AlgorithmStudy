#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    int a[5] = { 1,5,25,125,625 };
    pair<char, int> M[5] = { {'A', 0},{'E', 1},{'I', 2},{'O', 3},{'U', 4} };

    for (int i = 0; i < word.size(); i++) {
        int idx;
        for (int j = 0; j < 5; j++) {
            if (word[i] == M[j].first) {
                idx = M[j].second;
                break;
            }
        } //for

        answer++;
        for (int k = 0; k < idx; k++) {
            for (int p = 4; p >= i; p--) {
                answer += a[4 - p];
            }
        } //for  
    } //for

    return answer;
}