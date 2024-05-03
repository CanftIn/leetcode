class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int idx) {
        result.push_back(path);
        if (idx == nums.size()) {
            return;
        }
        for (int i = idx; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};
返回该题
