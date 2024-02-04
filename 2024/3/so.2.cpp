class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_set<char> lookup;
        int left = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (lookup.find(s[i]) != lookup.end()) {
                lookup.erase(s[left]);
                ++left;
            }
            max_len = max(max_len, i - left + 1);
            lookup.insert(s[i]);
        }
        return max_len;
    }
};