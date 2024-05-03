class Solution {
    vector<vector<string>> result;
    vector<string> path;

    void backtracking(const string& s, int idx) {
        if (idx >= s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = idx; i < s.size(); ++i) {
            if (isPalindorme(s, idx, i)) {
                string str = s.substr(idx, i - idx + 1);
                path.push_back(str);
            } else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    bool isPalindorme(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};
