class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum_left = 0;
        int sum_right = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            sum_right -= nums[i];
            if (sum_left == sum_right) {
                return i;
            }
            sum_left += nums[i];
        }
        return -1;
    }
};