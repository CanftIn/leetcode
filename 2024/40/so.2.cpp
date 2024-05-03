class Solution {
    vector<vector<int>> result;
    vector<int> path;

public:
    void backtracking(vector<int>& candidates, int target, int sum, int idx) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size() && sum + candidates[i] <= target; ++i) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
