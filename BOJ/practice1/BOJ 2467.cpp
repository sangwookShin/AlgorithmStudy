#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long arr[100000];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long result_a, result_b;
    int left = 0;
    int right = N - 1;
    result_a = arr[left];
    result_b = arr[right];
    long long result = abs(result_a + result_b);

    while (left < right) {

        long long sum = arr[left] + arr[right];

        if (abs(sum) < result) {
            result_a = arr[left];
            result_b = arr[right];
            result = abs(sum);
        }

        if (sum < 0) {
            left++;
        }
        else {
            right--;
        }

    } //while

    cout << result_a << " " << result_b;

    return 0;

}