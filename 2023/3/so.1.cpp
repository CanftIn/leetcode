class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        auto front = s.begin();
        auto end = s.begin() + 1;
        int max_len = 0;
        while (end != s.end()) {
            auto move = front;
            while (move != end) {
            if (*move == *end) {
                front = move + 1;
            }
            ++move;
            }
            int len = end - front + 1;
            if (len > max_len) max_len = len;
            ++end;
        }
        return max_len;
    }
};