class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int pre_num = getValue(s[0]);
        for (int i = 1; i < s.length(); ++i) {
            int num = getValue(s[i]);
            if (pre_num < num) {
                sum -= pre_num;
            } else {
                sum += pre_num;
            }
            pre_num = num;
        }
        sum += pre_num;
        return sum;
    }

    int getValue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};
