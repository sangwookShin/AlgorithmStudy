#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

bool is_prime(int a) { //소수 판별

    int n = sqrt(a);

    for (int i = 2; i <= n; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_pal(string a, string b) { //팰린드롬 판별
    if (a == b) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    if (N == 1) {
        cout << 2;
        return 0;
    }

    while (1) {

        string a = "";
        string b = "";

        a = to_string(N);
        b = to_string(N);
        reverse(b.begin(), b.end());

        if (is_pal(a, b)) {
            if (is_prime(N)) {
                cout << N;
                return 0;
            }
        }

        N++;
    } //while


    return 0;

}