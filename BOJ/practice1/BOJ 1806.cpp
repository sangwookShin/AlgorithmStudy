#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int N, S;

void solve() {

    int start = 0; //start, end 좌표를 처음 인덱스로 설정
    int end = 0;
    int sum = 0; //인덱스 이동시 그때의 합
    int result = 987654321; //결과

    while (start <= end) {
        if (sum >= S) { //합이 S이상일 경우
            result = min(result, end - start); //길이(start와 end의 인덱스차이)
            sum -= v[start++]; //start를 옆으로 이동, 이때 합에서 빼줘야함
        }
        else if (end == N) { //end가 마지막 이동시 멈춤
            break;
        }
        else { //end 인덱스 증가시키면서 합을 구함
            sum += v[end++];
        }
    } //while

    if (result == 987654321) {
        cout << 0;
    }
    else {
        cout << result;
    }

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    solve();

    return 0;
}