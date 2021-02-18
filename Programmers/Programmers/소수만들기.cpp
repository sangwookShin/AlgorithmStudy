#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool Prime_number(int n) { //소수 판별
    int cnt = 0;

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) cnt++;
    }
    if (cnt == 1) return 1;
    else return 0;
}

// nums_len은 배열 nums의 길이
int solution(int nums[], size_t nums_len) {
    int answer = 0;

    for (int i = 0; i < nums_len; i++) {
        for (int j = i + 1; j < nums_len; j++) {
            for (int k = j + 1; k < nums_len; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (Prime_number(sum) == 1)
                    answer++;
            }
        }
    }

    return answer;
}