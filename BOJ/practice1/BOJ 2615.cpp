#include <iostream>
#include <vector>

using namespace std;

int pan[25][25];

int rightCheck(int p, int q, int a) { //가로 검사

	for (int i = 1; i < 5; i++) {
		if (pan[p][q + i] != a) {
			return 0;
		}
	}

	//6목 검사
	if (pan[p][q + 5] == a || pan[p][q - 1] == a) {
		return 0;
	}
	else {
		return 1;
	}
}

int downCheck(int p, int q, int a) { //세로 검사

	for (int i = 1; i < 5; i++) {
		if (pan[p + i][q] != a) {
			return 0;
		}
	}

	//6목 검사
	if (pan[p + 5][q] == a || pan[p - 1][q] == a) {
		return 0;
	}
	else {
		return 1;
	}
}

int RDCheck(int p, int q, int a) { // 오른쪽 아래 검사

	for (int i = 1; i < 5; i++) {
		if (pan[p + i][q + i] != a) {
			return 0;
		}
	}

	//6목 검사
	if (pan[p + 5][q + 5] == a || pan[p - 1][q - 1] == a) {
		return 0;
	}
	else {
		return 1;
	}
}

int RUcheck(int p, int q, int a) { // 오른쪽 위 검사

	for (int i = 1; i < 5; i++) {
		if (pan[p - i][q + i] != a) {
			return 0;
		}
	}

	//6목 검사
	if (pan[p - 5][q + 5] == a || pan[p + 1][q - 1] == a) {
		return 0;
	}
	else {
		return 1;
	}
}

void solve() {

	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {

			if (pan[i][j] != 0) {

				int t = pan[i][j];

				if (downCheck(i, j, t) == 1) {
					cout << t << endl;
					cout << i << " " << j;
					return;
				}
				else if (rightCheck(i, j, t) == 1) {
					cout << t << endl;
					cout << i << " " << j;
					return;
				}
				else if (RDCheck(i, j, t) == 1) {
					cout << t << endl;
					cout << i << " " << j;
					return;
				}
				else if (RUcheck(i, j, t) == 1) {
					cout << t << endl;
					cout << i << " " << j;
					return;
				}
			}
		}
	}

	cout << 0;
}

int main() {

	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			int t;
			cin >> t;
			pan[i][j] = t;
		}
	}

	solve();

	return 0;

}