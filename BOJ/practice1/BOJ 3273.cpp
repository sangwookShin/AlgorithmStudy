#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int x;
    int arr[100000];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    sort(arr, arr + n);

    int start = 0;
    int end = n - 1;
    int result = 0;

    while (start < end) {

        if (arr[start] + arr[end] == x) {
            result++;
            end--;
        }
        else if (arr[start] + arr[end] < x) {
            start++;
        }
        else if (arr[start] + arr[end] > x) {
            end--;
        }
    } //while

    cout << result;

    return 0;

}