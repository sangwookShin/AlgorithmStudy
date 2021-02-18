#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> R;

long long f(long long n) {
    if (R[n] == 0) return n;
    return R[n] = f(R[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for (int i = 0; i < room_number.size(); i++) {

        long long n = room_number[i];
        if (R[n] == 0) {
            answer.push_back(n);
            R[n] = f(n + 1);
        }
        else {
            long long next_n = f(n);
            answer.push_back(next_n);
            R[next_n] = f(next_n + 1);
        }
    }
    return answer;
}