class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        function<void(int)> dfs = [&](int x) {
            if(x == n - 1) {
                ans.emplace_back(nums);
                return;
            }
            for(int i = x; i < n; i++) {
                swap(nums[i], nums[x]);
                dfs(x + 1);
                swap(nums[i], nums[x]);
            }
        };
        dfs(0);
        return ans;
    }
};