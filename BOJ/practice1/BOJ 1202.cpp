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

	sort(bag, bag + K); //가방 무게 오름차순 정렬
	sort(gem, gem + N); //보석 무게 오름차순 정렬

	for (int i = 0; i < K; i++) {

		while (idx < N && gem[idx].first <= bag[i]) { //보석 무게가 가방 무게보다 낮은 보석 가격들을 우선순위 큐에 넣어준다.
			pq.push(gem[idx].second);
			idx++;
		}
		if (!pq.empty()) { //maxheap 이기 때문에 맨위의 보석이 제일 비싸다. 이것을 결과값에 더해준다.
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