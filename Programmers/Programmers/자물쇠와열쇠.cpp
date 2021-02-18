#include <string>
#include <vector>

using namespace std;

int N, M;

vector<vector<int>> rotation(vector<vector<int>> key) {

    vector<vector<int>> tmp(M, vector<int>(M, 0));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            tmp[j][M - 1 - i] = key[i][j];
        }
    }
    return tmp;
}

int check(vector<vector<int>> key, vector<vector<int>> lock_a, int x, int y) { //맞으면 0

    int cnt = 0;

    for (int i = y, a = 0; i < y + M; i++, a++) {
        for (int j = x, b = 0; j < x + M; j++, b++) {
            lock_a[i][j] = lock_a[i][j] ^ key[a][b];
        }
    }

    for (int i = M - 1; i < M + N - 1; i++) {
        for (int j = M - 1; j < M + N - 1; j++) {
            if (lock_a[i][j] == 0) cnt++;
        }
    }

    return cnt;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

    N = lock.size();
    M = key.size();

    //새로운 큰 자물쇠
    vector<vector<int>> lock_a(N + 2 * M - 2, vector<int>(N + 2 * M - 2, 0));

    //큰 자물쇠에 원래 자물쇠 값 대입
    for (int i = M - 1, a = 0; i < N + M - 1; i++, a++) {
        for (int j = M - 1, b = 0; j < N + M - 1; j++, b++) {
            lock_a[i][j] = lock[a][b];
        }
    }

    for (int i = 0; i < M + N - 1; i++) {
        for (int j = 0; j < M + N - 1; j++) {
            vector<vector<int>> Ro_key = key;

            for (int k = 0; k < 4; k++) {
                if (check(Ro_key, lock_a, j, i) == 0) return true;
                Ro_key = rotation(Ro_key);
            }

        }
    }
    return false;
}