// Problem 565: Array Nesting
// https://leetcode.com/problems/array-nesting/

class Solution {
    public int arrayNesting(int[] nums) {
        // 宣告是否走過這個點的 boolean 陣列, 與預設最大長度為 0
        boolean[] visit = new boolean[nums.length];
        int longestLen = 0;

        // 由每個點都出發過
        for (int i = 0; i < nums.length; i++) {
            // idx 現在要走的位置, 預設現在的長度為 0
            int idx = i;
            int tempLen = 0;

            // 紀錄這點為走過, tempLen + 1, 更新 idx 為指引的下一步位置, 一直走值到該位置已走過
            while (!visit[idx]) {
                visit[idx] = true;
                tempLen++;
                idx = nums[idx];
            }
            // 如果 現在的長度 大於 最大長度, 則更新最大長度
            longestLen = Math.max(longestLen, tempLen);
        }
        return longestLen;
    }
}
