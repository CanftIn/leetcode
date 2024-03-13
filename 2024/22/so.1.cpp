class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return {};

        dfs("", 0, 0, n);
        return res;
    }

    void dfs(string paths, int left, int right, int n) {
        if (left > n || left < right) return;
        if (paths.size() == n * 2) {
            res.push_back(paths);
            return;
        }
        dfs(paths + '(', left + 1, right, n);
        dfs(paths + ')', left, right + 1, n);
    }
};
