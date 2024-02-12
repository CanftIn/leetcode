class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        for (int i = 0; i < nums.size(); ++i) {
            if (ht.count(target - nums[i])) {
                return {ht[target - nums[i]], i};
            }
            ht[nums[i]] = i;
        }
        return {};
    }
};