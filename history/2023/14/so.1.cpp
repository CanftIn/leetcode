class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first = strs[0];
        for (int i = 0; i < first.size(); ++i) {
            bool is_match = true;
            for (int j = 1; j < strs.size(); ++j) {
                if (first[i] != strs[j][i] || i == strs[j].size()) {
                    return first.substr(0, i);
                }
            }
        }
        return first;
    }
};