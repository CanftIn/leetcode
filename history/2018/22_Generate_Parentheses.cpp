class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
		addParentheses(res,"",n,0,0);
		return res;
	}
	void addParentheses(vector<string> &v, string str,int n,int Left,int Right)
	{
		if (Right == n)
		{
			v.push_back(str);
			return;
		}
		if (Left < n)	 
		addParentheses( v , str + '(', n , Left+1, Right );
		if (Left > Right)
		addParentheses( v , str + ')', n, Left , Right+1 );
	}
};