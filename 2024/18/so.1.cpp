class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int left = i + 1; left < nums.size() - 2; ++left) {
                if (left > i + 1 && nums[left] == nums[left - 1]) continue;
                int mid = left + 1;
                int right = nums.size() - 1;
                while (mid < right) {
                    long long four_sum = static_cast<long long>(nums[i]) + nums[left] + nums[mid] + nums[right];
                    if (four_sum < target) {
                        mid++;
                    } else if (four_sum > target) {
                        right--;
                    } else {
                        res.push_back({nums[i], nums[left], nums[mid], nums[right]});
                        mid++;
                        right--;
                        while (mid < right && nums[mid] == nums[mid - 1]) mid++;
                        while (mid < right && nums[right] == nums[right + 1]) right--;
                    }
                }
            }
        }
        return res;
    }
};