class Solution {
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int n, int k, int start_idx) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = start_idx; i <= (n - (k - path.size()) + 1); ++i) {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        int start_idx = 1;
        backtracking(n, k, start_idx);
        return result;
    }
};
