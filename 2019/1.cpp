class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            int temp = nums[i];
            if(m.count(target - temp) && m[target - temp] != i)
            {
                res.push_back(i);
                res.push_back(m[target - temp]);
                break;
            }
        }
        return res;
    }
};