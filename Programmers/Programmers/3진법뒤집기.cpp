#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;

    while (n) {
        int a;
        a = n % 3;
        v.push_back(a);
        n = n / 3;
    }

    reverse(v.begin(), v.end());

    int b = 1;
    for (int i = 0; i < v.size(); i++) {

        answer += v[i] * b;
        b *= 3;
    }

    return answer;
}