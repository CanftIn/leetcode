/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map_num;
        for (int i = 0; i < nums.size(); ++i) {
            if (map_num.find(target - nums[i]) != map_num.end()) {
                return {map_num[target - nums[i]], i};
            }
            map_num.insert({nums[i], i});
        }
        return {};
    }
};
// @lc code=end