#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int prices[], size_t prices_len) {
    int j;
    int* answer = (int*)malloc(prices_len * sizeof(int));
    for (int i = 0; i < prices_len; i++) {
        for (j = i + 1; j < prices_len; j++) {
            if (prices[j] < prices[i]) break;
        }
        if (j == prices_len) j--;
        answer[i] = j - i;
    }
    return answer;
}