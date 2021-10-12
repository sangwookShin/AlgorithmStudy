#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq; //우선순위큐 최소힙

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    while (pq.size() > 1 && pq.top() <= K) {

        int a, b, c;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        c = a + b * 2;
        pq.push(c);
        answer++;
    }

    if (pq.top() < K) {
        return -1;
    }
    return answer;
}