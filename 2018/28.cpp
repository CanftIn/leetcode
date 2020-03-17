class Solution {
public:
    int strStr(string haystack, string needle) {
        int count = 0;
        for(int i = 0; i < haystack.length(); ++i)
        {
            if(haystack[i] != needle[0])
            {
                return -1;
            }
           
        }
        for(int i = 0; i < haystack.length();)
        {
            for(int j = 0; j < needle.length();)
            {
                if(haystack[i] == needle[j])
                {
                    i++;
                    j++;
                    count++;
                }
                else
                {
                    i++;
                    count++;
                }
            }
            return count;
        }
    }
};