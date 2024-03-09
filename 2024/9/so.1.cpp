class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int raw = x;
        long long reverse = 0;
        int remainder = 0;
        while (x != 0) {
            remainder = x % 10;
            x /= 10;
            reverse = remainder + reverse * 10;
        }
        return reverse == raw ? true : false;
    }
};
