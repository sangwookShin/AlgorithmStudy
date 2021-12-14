#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int arr[500000];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int result[500000];

    stack<pair<int, int>> s; //≥Ù¿Ã, ¿Œµ¶Ω∫

    for (int i = 0; i < N; i++) {
        result[i] = 0;
    }

    for (int i = N - 1; i >= 0; i--) {

        while (!s.empty() && s.top().first < arr[i]) {
            result[s.top().second] = i + 1;
            s.pop();
        }
        s.push({ arr[i], i });
    }


    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

    return 0;
}