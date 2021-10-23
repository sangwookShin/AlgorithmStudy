#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    int arr2_row = arr2[0].size();

    for (int i = 0; i < arr1.size(); i++) {

        vector<int> v;
        for (int j = 0; j < arr2_row; j++) {

            int tmp = 0;
            for (int k = 0; k < arr1[0].size(); k++) {
                tmp += arr1[i][k] * arr2[k][j];
            }
            v.push_back(tmp);
        } //for
        answer.push_back(v);
    } //for

    return answer;
}