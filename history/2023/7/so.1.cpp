class Solution {
public:
    int reverse(int x) {
        if (x == 0) return x;
        int flag = 1;
        if (x < 0) {
            flag = -1;
            x = abs(x);
        }
        while (x % 10 == 0) {
            x = x / 10;
        }
        long long ret = 0;
        while (x != 0) {
            ret = ret * 10 + (x % 10);
            x /= 10;
        }
        if (ret > INT_MAX || ret < INT_MIN) return 0;
        return flag * ret;
    }
};