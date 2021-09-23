#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int start_x, start_y, start_d; // ó�� ������ġ, ����
int arr[51][51];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
pair<pair<int, int>, int> robot; //�κ�û�ұ��� ��ǥ, ����

void solve() {

	int result = 1;
	int nx, ny, nd;

	//�κ� û�ұ� ó�� ��ǥ, ���� ����
	robot.first.first = start_x;
	robot.first.second = start_y;
	robot.second = start_d;

	int x = start_x;
	int y = start_y;
	int d = start_d;

	//û���� �� 2�� ����
	arr[start_x][start_y] = 2;

	while (1) {

		int cnt = 0;
		int tmpd = d;

		for (int i = 0; i < 4; i++) { //�� ���� �˻�

			nd = (d + 3) % 4;
			nx = x + dx[nd];
			ny = y + dy[nd];

			if (arr[nx][ny] == 0) { //û�� ����
				arr[nx][ny] = 2;
				d = nd;
				result++;
				break;
			}
			else if (arr[nx][ny] == 1 || arr[nx][ny] == 2 || (nx < 0 || ny < 0 || nx >= N || ny >= M)) { //û�� �Ұ���
				d = nd;
				cnt++;
			}
		} //for

		if (cnt == 4) { //4���� ��� û�� �Ұ���
			nx = x - dx[tmpd];
			ny = y - dy[tmpd];
			d = tmpd;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == 1) { //�۵� ����
				break;
			}
		} //if

		x = nx;
		y = ny;
	} //while

	cout << result;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> start_x >> start_y >> start_d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	solve();

	return 0;
}