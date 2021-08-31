#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> tmp;

    for (int i = 0; i < n; i++) {

        tmp.clear();
        for (int j = 0; j < n; j++) { //2진수 만들어주면서 OR 연산을 통해 tmp에 넣기
            if (arr1[i] % 2 || arr2[i] % 2) {
                tmp.push_back("#");
            }
            else {
                tmp.push_back(" ");
            }
            arr1[i] = arr1[i] / 2;
            arr2[i] = arr2[i] / 2;
        }
        answer.push_back(tmp[n - 1]);
        for (int k = n - 2; k >= 0; k--) {
            answer[i] = answer[i] + tmp[k];
        }
    }

    return answer;
}