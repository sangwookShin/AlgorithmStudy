#include <string>
#include <vector>

using namespace std;

int to_binary(int n) { //2���� ��ȯ �� 1�� ���� ��ȯ

    int cnt = 0;

    while (n > 0) {

        if (n % 2 == 1) {
            cnt++;
        }
        n = n / 2;
    }

    return cnt;
}

int solution(int n) {
    int answer = n + 1;

    while (1) {
        if (to_binary(n) == to_binary(answer)) {
            break;
        }
        answer++;
    }

    return answer;
}