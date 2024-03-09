class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1 || (s.size() == 2 && s[0] == s[1])) 
            return s;

        int start = 0;
        int end = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = helper(s, i, i);
            int len2 = helper(s, i, i + 1);
            max_len = max(max(len1, len2), max_len);
            if (max_len > end - start + 1) {
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }
        }
        return s.substr(start, max_len);
    }

    int helper(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
};
