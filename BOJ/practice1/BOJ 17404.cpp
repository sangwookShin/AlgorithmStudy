#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int N;
    int home[1001][3];
    int dp[1001][3];
    int result = 987654321;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> home[i][0] >> home[i][1] >> home[i][2];
    } //for

    for (int one_color = 0; one_color < 3; one_color++) {

        for (int i = 0; i < 3; i++) {
            if (i == one_color) {
                dp[1][i] = home[1][i];
            }
            else {
                dp[1][i] = 987654321;
            }
        } //for

        for (int i = 2; i <= N; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + home[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + home[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + home[i][2];
        } //for

        for (int i = 0; i < 3; i++) {
            if (i == one_color) {
                continue;
            }
            else {
                result = min(result, dp[N][i]);
            }
        } //for

    }

    cout << result;

    return 0;

}