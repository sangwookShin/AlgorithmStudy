#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int parent[1000001];

int find(int a) { //�θ�ã��

    if (parent[a] == a) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a, int b) {

    a = find(a);
    b = find(b);
    if (a != b) {
        parent[a] = b;
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) { //�ڱ� �θ�� �ڱ��� ����
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {

        int c, a, b;
        cin >> c >> a >> b;

        if (c == 0) { //������ ����
            Union(a, b);
        }
        else if (c == 1) { //Ȯ��
            if (find(a) == find(b)) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }

    }

    return 0;

}