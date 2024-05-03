class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int sum = 0;
        int sum_len = 0;
        int i = 0;

        for (int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while (sum >= target) {
                sum_len = j - i + 1;
                result = result > sum_len ? sum_len : result;
                sum -= nums[i];
                i++;
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};
