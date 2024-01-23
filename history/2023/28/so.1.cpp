class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i <= n - m; ++i) {
            int j = i, k = 0;
            while (k < m && haystack[j] == needle[k]) {
                j++;
                k++;
            }
            if (k == m) return i;
        }
        return -1;
    }
};