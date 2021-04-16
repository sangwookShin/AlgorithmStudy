#include <string>
#include <vector>

using namespace std;

int answer;

bool check(vector<int> stones, int k, int mid) {

    int cnt = 0;

    for (int i = 0; i < stones.size(); i++) {

        if (stones[i] - (mid - 1) <= 0) {
            cnt++;
            if (cnt == k) {
                return false;
            }
        }
        else {
            cnt = 0;
        }
    }

    return true;
}

void binarySearch(vector<int> stones, int k, int l, int r) {

    if (l > r)
        return;

    int mid = (l + r) / 2;
    bool result = check(stones, k, mid);

    if (result == true) {

        if (answer < mid) {
            answer = mid;
        }

        binarySearch(stones, k, mid + 1, r);


    }
    else {
        binarySearch(stones, k, l, mid - 1);
    }


}
int solution(vector<int> stones, int k) {
    answer = 0;


    binarySearch(stones, k, 1, 200000000);
    return answer;

}