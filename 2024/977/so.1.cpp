class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        int i = 0;
        int j = k;
        vector<int> res(nums.size(), 0);
        while (i <= j) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                res[k] = nums[j] * nums[j];
                --j;
            } else {
                res[k] = nums[i] * nums[i];
                ++i;
            }
            --k;
        }
        return res;
    }
};
