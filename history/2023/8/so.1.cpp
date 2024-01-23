class Solution {
public:
    int myAtoi(string s) {
        if (s == "") return 0;
        auto pos = s.begin();
        string copy = s;
        int negative = 1;
        long long ret = 0;
        // eliminate space
        while (*pos == ' ') {
            pos++;
        }
        if (*pos == '-') {
            negative = -1;
            pos++;
        } else if (*pos == '+') {
            pos++;
        }

        while ('0' <= *pos && *pos <= '9') {
            ret = ret * 10 + *pos - '0';
            if (ret > INT_MAX) {
                break;
            }
            ++pos;
        }
        ret = negative * ret;
        if (INT_MIN <= ret && ret <= INT_MAX)
            return ret;
        else if (ret > INT_MAX)
            return INT_MAX;
        else if (ret < INT_MIN)
            return INT_MIN;
        return 0;
    }
};