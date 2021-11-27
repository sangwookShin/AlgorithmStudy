#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq1; //��������
    priority_queue<int> pq2; //��������, 1�� �� ���ƾ� ��

    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (pq2.size() > pq1.size()) {
            pq1.push(x);
        }
        else {
            pq2.push(x);
        }

        if (!pq1.empty() && !pq2.empty()) {

            int a = pq1.top();
            int b = pq2.top(); //�� �۾ƾ���

            if (b > a) {
                pq1.pop();
                pq2.pop();
                pq1.push(b);
                pq2.push(a);
            }

        }

        cout << pq2.top() << "\n";
    } //for


    return 0;
}