//플로이드 와샬, 브루트포스 이용

#include <string>
#include <vector>
#define INF 98765321;
using namespace std;

int DP[201][201];

void floydWarshall(int n) {

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (DP[i][k] + DP[k][j] < DP[i][j]) {
                    DP[i][j] = DP[i][k] + DP[k][j];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = 0;
    int r1;
    int r2 = INF;

    for (int i = 1; i <= n; i++) { //초기화
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                DP[i][j] = 0;
            }
            else {
                DP[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < fares.size(); i++) { //입력
        int start, e, w;
        start = fares[i][0];
        e = fares[i][1];
        w = fares[i][2];
        DP[start][e] = min(DP[start][e], w);
        DP[e][start] = min(DP[e][start], w);
    }

    floydWarshall(n);

    r1 = DP[s][a] + DP[s][b]; // s>a + s>b

    for (int i = 1; i <= n; i++) {
        r2 = min(r2, DP[s][i] + DP[i][a] + DP[i][b]);
    }

    answer = min(r1, r2);
    return answer;
}