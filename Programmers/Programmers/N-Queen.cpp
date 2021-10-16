#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[12];
int answer = 0;

bool check(int r) {

    for (int i = 0; i < r; i++) {
        if (arr[i] == arr[r] || abs(arr[i] - arr[r]) == abs(i - r)) {
            return false;
        }
    }

    return true;
}
void backtracking(int r, int n) {

    if (r == n) {
        answer++;
    }
    else {
        for (int i = 0; i < n; i++) {
            arr[r] = i;
            if (check(r)) {
                backtracking(r + 1, n);
            }
        }
    }

}
int solution(int n) {

    backtracking(0, n);
    return answer;
}