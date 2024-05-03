class Solution {
    vector<vector<int>> result;
    vector<int> path;

public:
    void backtracking(vector<int>& candidates, int target, int idx, int sum) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i, sum);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
