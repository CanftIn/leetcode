class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int res = 100000;
        for (int i = 0; i < nums.size() - 2; ++i) {
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                int val = target - nums[i] - nums[j];
                int idx = binarySearch(nums, j + 1, nums.size() - 1, val);
                if (val == nums[idx]) return target;
                if (abs(val - nums[idx]) < abs(res - target))
                    res = nums[i] + nums[j] + nums[idx];
                if (idx - 1 > j && abs(val - nums[idx - 1]) < abs(res - target)) {
                    res = nums[i] + nums[j] + nums[idx - 1];
                }
            }
        }
        return res;
    }

    int binarySearch(const vector<int>& nums, int left, int right, int target) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};