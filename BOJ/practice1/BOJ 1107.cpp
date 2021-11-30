#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N, M;
bool button[10]; //true면 고장난 버튼

bool is_ok(int n) {

    if (n == 0) {
        if (button[0] == 1) {
            return false;
        }
        return true;
    }

    while (n) {
        if (button[n % 10] == true) {
            return false;
        }
        n = n / 10;
    }

    return true;
}

void solve() {

    int pressPM = abs(N - 100); //+/-버튼으로만 가는 경우
    int result = 987654321;
    int leng;

    for (int i = 0; i <= 1000001; i++) {

        if (is_ok(i)) {
            leng = to_string(i).length();
            leng += abs(i - N);
            result = min(result, leng);
        }
    }

    cout << min(result, pressPM);
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        button[a] = true;
    }

    solve();

    return 0;

}