class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end(), [](const string str1, const string str2)->bool{
            return str1 < str2;
        });
        string prefix = strs[0];
        
        for(int i = 1; i < strs.size(); ++i)
        {
            for(int c = 0; c < prefix.size(); ++c)
            {
                if(strs[i][c] != prefix[c])
                {
                    prefix = prefix.substr(0, c);
                    break;
                }
            }
        }
        return prefix;
    }
};