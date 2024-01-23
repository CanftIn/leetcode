class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int tmp_nearest = INT_MAX;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int z = j + 1; z < nums.size(); ++z) {
                    int sum = nums[i] + nums[j] + nums[z];
                    int distance = abs(target - sum);
                    if (tmp_nearest > distance) {
                        tmp_nearest = distance;
                        res = sum;
                    }
                }
            }
        }
        return res;
    }
};