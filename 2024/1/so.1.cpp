class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = ht.find(target - nums[i]);
            if (it != ht.end()) {
                return {it->second, i};
            }
            ht[nums[i]] = i;
        }
        return {};
    }
};