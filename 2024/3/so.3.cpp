class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        unordered_set<char> store;
        int left = 0;
        int right = 0;
        int max_length = 0;
        while (left <= right && right < s.size()) {
            if (store.count(s[right])) {
                store.erase(s[left]);
                left++;
            } else {
                max_length = max(max_length, right - left + 1);
                store.insert(s[right]);
                right++;
            }
        }
        return max_length;
    }
};