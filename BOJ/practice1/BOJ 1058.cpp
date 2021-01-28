#include <iostream>
#include <vector>
using namespace std;

int N;
int Friend[51][51];

void findMostFamousPerson(vector<string>& row) {

	int max=0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) 
				Friend[i][j] = 0; //자기자신
			else if (row[i][j] == 'Y')
				Friend[i][j] = 1; //친구
			else
				Friend[i][j] = 99999; //친구아님
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (Friend[i][j] == 0 || Friend[i][k] == 0 || Friend[j][k] == 0)
					continue;
				else if (Friend[i][j] + Friend[i][k] < Friend[j][k])
					Friend[j][k] = Friend[i][j] + Friend[i][k];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (Friend[i][j] == 0)
				continue;
			else if (Friend[i][j] <= 2)
				sum++;
		}
		if (max < sum)
			max = sum;
	}

	cout << max;
}

int main() {

	vector<string> row;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		row.push_back(tmp);
	}

	findMostFamousPerson(row);

	return 0;
}