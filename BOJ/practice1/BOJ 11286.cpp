#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //디폴트 = 내림차순
    priority_queue<int, vector<int>, greater<int>> pq1; //오름차순 : 양수저장
    priority_queue<int> pq2; //내림차순 : 음수 저장

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {

        int x;
        cin >> x;
        if (x == 0) {
            if (pq1.empty() && pq2.empty()) {
                cout << "0\n";
            }
            else if (pq1.empty()) {
                cout << pq2.top() << "\n";
                pq2.pop();
            }
            else if (pq2.empty()) {
                cout << pq1.top() << "\n";
                pq1.pop();
            }
            else {

                if (pq1.top() < -pq2.top()) {
                    cout << pq1.top() << "\n";
                    pq1.pop();
                }
                else {
                    cout << pq2.top() << "\n";
                    pq2.pop();
                }

            } //else
        } //if
        else if (x > 0) {
            pq1.push(x);
        }
        else if (x < 0) {
            pq2.push(x);
        }

    }

    return 0;
}