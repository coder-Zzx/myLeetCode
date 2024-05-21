/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    void backtracing(vector<vector<int>>& res, vector<int>& nums,
                     vector<int>& candidates, int sum, int target, int n,
                     int start) {
        if (sum >= target) {
            if (sum == target) {
                res.push_back(nums);
            }
            return;
        }
        for (int i = start; i < n && sum + candidates[i] <= target; i++) {
            nums.push_back(candidates[i]);
            backtracing(res, nums, candidates, sum + candidates[i], target, n,
                        i);
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> nums;
        sort(candidates.begin(), candidates.end());
        backtracing(res, nums, candidates, 0, target, candidates.size(), 0);
        return res;
    }
};
// @lc code=end
