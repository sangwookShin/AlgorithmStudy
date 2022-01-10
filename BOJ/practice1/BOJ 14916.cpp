#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n % 5 == 0) { //5원으로 나눠줄수 있는 경우
        cout << n / 5;
        return 0;
    }

    int five;
    five = n / 5;

    while (five >= 0) {
        int result = (n - (five * 5)) % 2;
        if (result % 2 == 0) {
            cout << five + ((n - (five * 5)) / 2);
            return 0;
        }
        five--;
    }

    cout << -1;

    return 0;
}