class Solution {
public:
    int myAtoi(string str) {
        long long ret = 0;
        int strSize = str.size();
        int flag = 1; // + or -
        bool start = false; // flag of starting read number 
        for (int i = 0; i < strSize; ++i) {
            if (str[i] == ' ' && start == false)
                continue;
            if (str[i] == '-' && start == false) {
                flag = -1;
                start = true;
                continue;
            }
            if (str[i] == '+' && start == false) {
                flag = 1;
                start = true;
                continue;
            }
            if (str[i] >= '0' && str[i] <= '9') {
                start = true;
                ret = ret * 10 + str[i] - 48;
                if(flag*ret > INT_MAX)
                    return INT_MAX;
                if(flag*ret < INT_MIN)
                    return INT_MIN;
                continue;
            }
            else
                break;
        }
        return flag * ret;
    }
};