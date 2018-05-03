class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x != 0 && x % 10 == 0) return false;
        int palind = x;
        int rev = 0;
        while(x != 0)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev == palind;
    }
};