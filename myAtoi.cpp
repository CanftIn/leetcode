#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int myAtoi(string str)
{
    if(str.size() < 1) return 0;
    int i = 0, sign = 1;
    long retNum = 0;
    while(str[i] == ' ') ++i;
    if(i >= str.size()) return 0;
    if(str[i] == '+' || str[i] == '-' || isdigit(str[i]))
    {
        sign = str[i] == '-' ? -1 : 1;
        if(!isdigit(str[i])) ++i;
        while(i < str.size() && isdigit(str[i]))
        {
            retNum = retNum * 10 + ((str[i++] - '0') % 48);
            if(retNum > INT_MAX) return sign > 0 ? INT_MAX : INT_MIN;
        }
    }
    else
        return 0;
    return int(retNum) * sign;
}

int main()
{
    string str = "-12a34";
    int num = myAtoi(str);
    std::cout << num << std::endl;
    return 0;
}