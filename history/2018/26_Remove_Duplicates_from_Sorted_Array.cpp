class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
            return 0;
        int count = 0;
        for(int a = 0; a < length; a++)
        {
            if(nums[count] != nums[a])
            {
                nums[++count]= nums[a];
            }
        }
        return count + 1;
    }
};