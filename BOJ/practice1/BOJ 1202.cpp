#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
long long bag[300001];
pair<int, long long> gem[300001];
priority_queue<int> pq;

void solve() {

	long long result = 0;
	int idx = 0;

	sort(bag, bag + K); //���� ���� �������� ����
	sort(gem, gem + N); //���� ���� �������� ����

	for (int i = 0; i < K; i++) {

		while (idx < N && gem[idx].first <= bag[i]) { //���� ���԰� ���� ���Ժ��� ���� ���� ���ݵ��� �켱���� ť�� �־��ش�.
			pq.push(gem[idx].second);
			idx++;
		}
		if (!pq.empty()) { //maxheap �̱� ������ ������ ������ ���� ��δ�. �̰��� ������� �����ش�.
			result = result + pq.top();
			pq.pop();
		}
	}

	cout << result;
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> gem[i].first >> gem[i].second;
	}

	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}

	solve();

	return 0;
}