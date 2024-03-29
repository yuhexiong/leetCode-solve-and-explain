// Problem 899: Orderly Queue
// https://leetcode.com/problems/orderly-queue/

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            // 如果 k > 1, 在可以排無限次的情況下, 一定有辦法全部排好
            sort(s.begin(), s.end());
            return s;
        } else {
            // 如果 k = 1, 找到所有可能的移動組合，取 lexicographically smallest
            string result = s;
            for (int i = 1; i < s.length(); ++i) {
                result = min(result, s.substr(i) + s.substr(0, i));
            }
            return result;
        }
    }
};
