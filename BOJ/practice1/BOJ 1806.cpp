#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int N, S;

void solve() {

    int start = 0; //start, end ��ǥ�� ó�� �ε����� ����
    int end = 0;
    int sum = 0; //�ε��� �̵��� �׶��� ��
    int result = 987654321; //���

    while (start <= end) {
        if (sum >= S) { //���� S�̻��� ���
            result = min(result, end - start); //����(start�� end�� �ε�������)
            sum -= v[start++]; //start�� ������ �̵�, �̶� �տ��� �������
        }
        else if (end == N) { //end�� ������ �̵��� ����
            break;
        }
        else { //end �ε��� ������Ű�鼭 ���� ����
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