#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> v[100001];
bool visit[100001];
int result[100001];

void DFS(int start) {

    visit[start] = true;

    for (int i = 0; i < v[start].size(); i++) {

        int next = v[start][i];

        if (visit[next] == false) {
            result[next] = start;
            DFS(next);
        }

    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);

    for (int i = 2; i <= N; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}