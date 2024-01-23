class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);
        for (int i = 0; i < str.size(); i++) 
            for (int j = str.size()-1; j >= i; j--) 
                if ((str[i] - str[j])%2 == 0 && str[i] < str[j]) 
                    swap(str[i], str[j]);
        return atoi(str.c_str());       
    }
};