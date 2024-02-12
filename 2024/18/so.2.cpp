class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return nSumTarget(nums, 4, 0, target);
    }

    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
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

    vector<vector<int>> nSumTarget(vector<int>& nums, int n, int start, long long target) {
        int sz = nums.size();
        vector<vector<int>> res;
        if (n < 2 || sz < n) return res;
        if (n == 2) {
            int lo = start, hi = sz - 1;
            while (lo < hi) {
                long long sum = static_cast<long long>(nums[lo] + nums[hi]);
                int left = nums[lo], right = nums[hi];
                if (sum < target) {
                    while (lo < hi && nums[lo] == left) lo++;
                } else if (sum > target) {
                    while (lo < hi && nums[hi] == right) hi--;
                } else {
                    res.push_back({left, right});
                    while (lo < hi && nums[lo] == left) lo++;
                    while (lo < hi && nums[hi] == right) hi--;
                }
            }
        } else {
            for (int i = start; i < sz; ++i) {
                vector<vector<int>> sub = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
                for (vector<int>& arr : sub) {
                    arr.push_back(nums[i]);
                    res.push_back(arr);
                }
                while (i < sz - 1 && nums[i] == nums[i + 1]) ++i;
            }
        }
        return res;
    }
};