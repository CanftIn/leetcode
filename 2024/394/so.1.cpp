class Solution {
    string dfs(string s, int& i) {
        string res = "";
        int count = 0;
        while (i < s.size()) {
            if ('0' <= s[i] && s[i] <= '9') {
                count = count * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                string tmp = dfs(s, ++i);
                while (count > 0) {
                    res += tmp;
                    count--;
                }
                count = 0;
            } else if (s[i] == ']') {
                return res;
            } else {
                res += s[i];
            }
            ++i;
        }
        return res;
    }

public:
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }
};