#include<iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

string number;
void rotate() {
    char save = number[number.size() - 1];
    for (int i = number.size() - 1; i >= 1; i--) {
        number[i] = number[i - 1];
    }
    number[0] = save;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    vector<int> v; //수를 저장할 벡터

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, K;
        cin >> N >> K >> number;
        int p = N / 4;

        for (int q = 0; q < p; q++) {

            for (int i = 0; i < 4; i++) {

                int sum = 0;
                int m = 1;
                bool check = false;

                for (int j = 0; j < p; j++) {
                    //16진수변환
                    if (number[i * p + j] >= 'A') {
                        sum += (number[i * p + j] - 'A' + 10) * pow(16, p - j - 1);
                    }
                    else {
                        sum += (number[i * p + j] - '0') * pow(16, p - j - 1);
                    }
                } //for

                for (auto f : v) {
                    if (f == sum) {
                        check = true;
                    }
                }
                if (check == false) {
                    v.push_back(sum);
                }
            } //for

            rotate();
        } //for

        sort(v.begin(), v.end());
        cout << "#" << test_case << " " << v[v.size() - K] << "\n";
        v.clear();
    } //for 전체

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}