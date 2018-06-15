class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int sum = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            sum = nums[i] + (sum < 0 ? 0:sum);
            max = sum > max ? sum:max;
        }
        return max;
    }
};