#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    if (a == 0) {
        return b;
    }
    return GCD(b % a, a);
}
int LSM(int a, int b) {
    return a * b / GCD(a, b);
}
int solution(vector<int> arr) {
    int answer = 0;
    answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        answer = (LSM(answer, arr[i]));
    }

    return answer;
}