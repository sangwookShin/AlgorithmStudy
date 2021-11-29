#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int arr[1001][3];
    int result;

    cin >> N;

    arr[0][0] = 0;
    arr[0][1] = 0;
    arr[0][2] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

        arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + arr[i][0];
        arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + arr[i][1];
        arr[i][2] = min(arr[i - 1][1], arr[i - 1][0]) + arr[i][2];
    }

    result = min(arr[N][0], min(arr[N][1], arr[N][2]));

    cout << result;

    return 0;
}