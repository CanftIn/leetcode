class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();  
        int result = 0 ;  
        for (int i=0; i<length; i++)  
        {  
            result ^= nums[i];  
        }  
        return result;  
    }
};