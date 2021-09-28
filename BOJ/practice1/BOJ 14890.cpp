#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int arr1[101][101];
int arr2[101][101];
int result = 0;

bool MakeRoad(int arr[101][101], int a, int b) {

    for (int i = b + 1; i < b + 1 + L; i++) { //L길이까지 중 높이가 다른게 있으면 경사로를 설치 못함
        if (arr[a][i] != arr[a][b + 1]) {
            return false;
        }
    }

    return true;
}

void solve(int arr[101][101]) {

    for (int i = 0; i < N; i++) {

        int cur_length = 1;
        bool can = true;

        for (int j = 0; j < N - 1; j++) {

            if (arr[i][j] == arr[i][j + 1]) { //높이가 같을 때
                cur_length++;
            }
            else if (arr[i][j] == arr[i][j + 1] + 1) {    //앞 = 뒤 + 1

                if (MakeRoad(arr, i, j) == true) {
                    cur_length = 0;
                    j = j + L - 1;
                }
                else {
                    can = false;
                    break;
                }
            }
            else if (arr[i][j] + 1 == arr[i][j + 1]) {  //앞 + 1 = 뒤

                if (cur_length >= L) {
                    cur_length = 1;
                }
                else {
                    can = false;
                    break;
                }
            }
            else if (abs(arr[i][j] - arr[i][j + 1]) >= 2) { //높이가 2 이상
                can = false;
                break;
            }
        } //for

        if (can == true) { //가능하면 추가
            result++;
        }

    } //for

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr1[i][j];
            arr2[j][i] = arr1[i][j];
        }
    }

    solve(arr1);
    solve(arr2);

    cout << result;

    return 0;
}