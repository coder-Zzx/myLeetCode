/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        if (points.size() <= 1) {
            return points.size();
        }
        sort(points.begin(), points.end(),
             [](const vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        int range = points[0][1];
        int res = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= range) {
                range = min(points[i][1], range);
            } else {
                range = points[i][1];
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
#ifndef __ONLINE_JUDGE__
int main() {
    Solution s;
    vector<vector<int>> points = {{1, 9},  {7, 16}, {2, 5}, {7, 12}, {9, 11},
                                  {2, 10}, {9, 16}, {3, 9}, {1, 3}};
    int res = s.findMinArrowShots(points);
    cout << res << endl;
    return 0;
}
#endif