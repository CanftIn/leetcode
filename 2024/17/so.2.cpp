class Solution {  
public:  
    vector<string> board = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};  
    vector<string> ans;
    string path;
  
    void backtracking(int pos, string digits) {  
        if (pos == digits.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < board[digits[pos] - '0'].size(); ++i) {
            path += board[digits[pos] - '0'][i];
            backtracking(pos + 1, digits);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backtracking(0, digits);
        return ans;
    }
};
