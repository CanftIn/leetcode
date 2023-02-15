class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> S;
        for (auto iter = s.begin(); iter != s.end(); ++iter)
        {
            if (*iter == '(' || *iter == '[' || *iter == '{')
                S.push(*iter);
            else
            {
                if (S.empty())
                    return false;
                if (*iter == ')' && S.top() != '(')
                    return false;
                if (*iter == ']' && S.top() != '[')
                    return false;
                if (*iter == '}' && S.top() != '{')
                    return false;
                S.pop();
            }
        }
        return S.empty();
    }
};