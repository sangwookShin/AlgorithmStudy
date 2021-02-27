//�Ｚ sw �����׽�Ʈ ���� ����
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int A[51][51];
bool check[13];
int result = 987654321;
vector<pair<int, int>> house, chickenhouse;

int distance(int r, int c, int x, int y) { //ġŲ �Ÿ�

	return abs(r - x) + abs(c - y);
}

void solve(int start, int select) { //DFS �̿�

	if (select == M) {

		int tmpresult = 0;
		for (int i = 0; i < house.size(); i++) {

			int dis = 987654321;

			for (int j = 0; j < chickenhouse.size(); j++) {

				if (check[j])
					dis = min(dis, distance(house[i].first, house[i].second, chickenhouse[j].first, chickenhouse[j].second));
			}
			tmpresult += dis;
		}
		result = min(result, tmpresult);
		return;
	}

	if (start == chickenhouse.size())
		return;

	//���������� ����
	check[start] = true;
	solve(start + 1, select + 1);

	//���
	check[start] = false;
	solve(start + 1, select);

}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];

			if (A[i][j] == 1)
				house.push_back({ i, j });
			else if (A[i][j] == 2)
				chickenhouse.push_back({ i,j });
		}
	}

	solve(0, 0);

	cout << result;

	return 0;
}