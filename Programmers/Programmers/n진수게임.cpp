#include <string>
#include <vector>

using namespace std;

char arr[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

string game(int a, int n) {

    string result = "";

    while (a / n != 0) {

        string tmp = result;
        result = arr[a % n];
        result += tmp;
        a /= n;
    }

    string tmp = result;
    result = arr[a % n];
    result += tmp;

    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string result = "";

    for (int i = 0; i < t * m; i++) {
        result += game(i, n);
    }

    int cnt = 0;

    for (int i = p - 1; i < result.size(), cnt < t; i = i + m) {
        answer += result[i];
        cnt++;
    }

    return answer;
}