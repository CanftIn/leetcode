#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
	int i = 0;
	while (i <= nums.size() - 1)
	{
		if (i == nums.size() - 1)
			return true;
		else if (i > nums.size() - 1)
			return false;
		int a = nums[i];
		i += a;
	} 
	
}

int main()
{
	int num[] = { 2,3,1,1,4 };
	vector<int> vec(&num[0], &num[5]);
	bool re = canJump(vec);
	return 0;
}