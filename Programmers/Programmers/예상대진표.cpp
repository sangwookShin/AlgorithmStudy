#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    if (b < a) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (1) {

        answer++;

        if (b - a == 1 && b % 2 == 0) {
            return answer;
        }

        if (a % 2 == 0) {
            a = a / 2;
        }
        else {
            a = a / 2 + 1;
        }

        if (b % 2 == 0) {
            b = b / 2;
        }
        else {
            b = b / 2 + 1;
        }

    } //while

    return answer;
}