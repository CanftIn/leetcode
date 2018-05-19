class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int idx = 0;
        for(auto iter = nums.begin(); iter != nums.end(); ++iter)
        {
            if(*iter == target)
            {
                return idx;
            }
            idx++;
        }
        return -1;
    }
};