class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, bool> alpha_map;
        for (char c : s) {
            alpha_map[c] = alpha_map.find(c) == alpha_map.end();
        }
        for (int i = 0; i < s.size(); ++i) {
            if (alpha_map[s[i]]) {
                return i;
            }
        }
        return -1;
    }
};