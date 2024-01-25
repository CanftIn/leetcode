class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }
        stack<char> mystack;
        map<char, char> mymap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (int i = 0; i < s.size(); ++i) {
            if (mymap.count(s[i])) {
                if (mystack.empty() || mystack.top() != mymap[s[i]]) {
                    return false;
                }
                mystack.pop();
            } else {
                mystack.push(s[i]);
            }
        }
        return mystack.empty();
    }
};