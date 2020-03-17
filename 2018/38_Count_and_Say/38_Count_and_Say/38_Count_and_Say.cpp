#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) 
{
	if (n == 1) return "1"; // base case
	string res, tmp = countAndSay(n - 1); // recursion
	char c = tmp[0];
	int count = 1;
	for (int i = 1; i<tmp.size(); i++)
		if (tmp[i] == c)
			count++;
		else 
		{
			res += to_string(count);
			res.push_back(c);
			c = tmp[i];
			count = 1;
		}
	res += to_string(count);
	res.push_back(c);
	return res;
}

int main()
{
	cout << countAndSay(4) << endl;
	cin.get();
	return 0;
}