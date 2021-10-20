#include <iostream>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, k;
    cin >> T;

    for (int i = 0; i < T; i++) {

        priority_queue<pair<int, int>> max_pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;
        bool visit[1000000];

        cin >> k;
        for (int j = 0; j < k; j++) {

            char c;
            int n;
            cin >> c >> n;

            if (c == 'I') {
                max_pq.push({ n, j });
                min_pq.push({ n, j });
                visit[j] = true;
            }
            else if (c == 'D') {

                if (n == 1) {
                    while (!max_pq.empty() && visit[max_pq.top().second] == false) {
                        max_pq.pop();
                    }
                    if (!max_pq.empty())
                    {
                        visit[max_pq.top().second] = false;
                        max_pq.pop();
                    }
                }
                else if (n == -1) {
                    while (!min_pq.empty() && visit[min_pq.top().second] == false) {
                        min_pq.pop();
                    }
                    if (!min_pq.empty())
                    {
                        visit[min_pq.top().second] = false;
                        min_pq.pop();
                    }
                }


            } //else if

        } //for
        while (!max_pq.empty() && visit[max_pq.top().second] == false) {
            max_pq.pop();
        }
        while (!min_pq.empty() && visit[min_pq.top().second] == false) {
            min_pq.pop();
        }

        if (max_pq.empty() && min_pq.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << max_pq.top().first << " " << min_pq.top().first << "\n";
        }
    }//for

    return 0;
}