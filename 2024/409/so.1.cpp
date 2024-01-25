class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counter;
        for (char c : s) {
            counter[c]++;
        }
        int res = 0, odd = 0;
        for (auto kv : counter) {
            int count = kv.second;
            int rem = count % 2;
            res += count - rem;
            if (rem == 1) odd = 1;
        }
        return res + odd;
    }
};