class Solution {
public:
    string reverseWords(string s) {
        vector<string> tokens;
        split(s, tokens, " ");
        reverse(tokens.begin(), tokens.end());
        ostringstream oss;
        for (auto token : tokens) {
            oss << token;
            oss << " ";
        }
        return oss.str().substr(0, oss.str().length() - 1);
    }


    void split(const string& s, vector<string>& tokens, const string& delimiter) {
        auto last_pos = s.find_first_not_of(delimiter, 0);
        auto pos = s.find_first_of(delimiter, last_pos);
        while (pos != string::npos || last_pos != string::npos) {
            tokens.push_back(s.substr(last_pos, pos - last_pos));
            last_pos = s.find_first_not_of(delimiter, pos);
            pos = s.find_first_of(delimiter, last_pos);
        }
    }
};