#include <string>
#include <vector>
#include <cstring>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int dp[101][101];
    bool water[101][101];

    memset(water, false, sizeof(water));
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < puddles.size(); i++) { //물이 있는 곳은 true
        water[puddles[i][1]][puddles[i][0]] = true;
    }

    dp[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (water[i][j] == true) {
                dp[i][j] = 0;
            }
            else if (i == 1 && j == 1) {
                continue;
            }
            else {
                dp[i][j] = (dp[i - 1][j] % 1000000007) + (dp[i][j - 1] % 1000000007);
                dp[i][j] = dp[i][j] % 1000000007;
            }
        }
    }

    answer = dp[n][m];
    return answer;
}