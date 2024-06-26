// Problem 69: Sqrt(x)
// https://leetcode.com/problems/sqrtx/


class Solution {
    public int mySqrt(int x) {
        long r = 0;
        // 跑迴圈, 如果目前 r 的平方還小於等於 x 則 + 1
        while (r * r <= x) {
            r++;
        }
        // 超過 x 才會跳脫, 所以最後要 - 1
        return (int)r - 1;  
    }
};