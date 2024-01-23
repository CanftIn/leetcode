class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        int tmp_nearest = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int distance = abs(target - sum);
                if (tmp_nearest > distance) {
                    tmp_nearest = distance;
                    res = sum;
                }
                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    return target;
                }
            }
        }
        return res;
    }
};