class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty()) return ;
        int counts[3] = {0};
        int length = nums.size();
        for(int i = 0; i < length; ++i)
            counts[nums[i]] += 1;
        int index = 0;
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < counts[i]; ++j)
            {
                nums[index++] = i;
            }
        }
    }
};