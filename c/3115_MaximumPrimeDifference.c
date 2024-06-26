// Problem 3115: Maximum Prime Difference
// https://leetcode.com/problems/maximum-prime-difference/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int num) {
    if (num == 1) {
        return false;
    }

    int divisor = 2;
    while (divisor * divisor <= num) {
        if (num % divisor == 0) {
            return false;
        }
        divisor += 1;
    }
    return true;
}

int maximumPrimeDifference(int* nums, int numsSize) {
    // 跑迴圈找左邊的質數
    int leftIndex = 0;
    for (int i = 0; i < numsSize; i++) {
        if (isPrime(nums[i])) {
            leftIndex = i;
            break;
        }
    }

    // 跑迴圈從後面往回找右邊的質數, 最多找到 leftIndex 後面一個, 沒找到就使用 leftIndex
    int rightIndex = leftIndex;
    for (int i = numsSize - 1; i > leftIndex; i--) {
        if (isPrime(nums[i])) {
            rightIndex = i;
            break;
        }
    }

    return rightIndex - leftIndex;
}