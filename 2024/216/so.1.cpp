class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int k, int n, int sum, int start_idx) {
        if (sum > n) {
            return;
        }
        if (path.size() == k) {
            if (sum == n)
                result.push_back(path);
            return;
        }

        for (int i = start_idx; i <= 9; ++i) {
            path.push_back(i);
            sum += i;
            backtracking(k, n, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 0, 1);
        return result;
    }
};
