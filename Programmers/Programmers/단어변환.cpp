#include <string>
#include <vector>

using namespace std;

bool check[50];
int answer = 100;

void dfs(string begin, string target, vector<string> words, int result) {

    if (begin == target) {
        answer = min(answer, result);
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < words[i].size(); j++) {
            if (begin[j] != words[i][j]) {
                cnt++;
            }
            if (cnt == 2) {
                break;
            }
        }
        if (cnt == 1) {
            if (check[i] == false) {
                check[i] = true;
                dfs(words[i], target, words, result + 1);
                check[i] = false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    dfs(begin, target, words, 0);

    if (answer == 100) {
        answer = 0;
    }

    return answer;
}