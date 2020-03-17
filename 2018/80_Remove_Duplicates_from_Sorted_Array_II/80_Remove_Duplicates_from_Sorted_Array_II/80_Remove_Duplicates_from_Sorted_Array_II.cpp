#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	/*int count = 0;
	int length = nums.size();
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		if (nums[i] == nums[i + 1])
		{
			count++;
			if (count == 2)
			{
				length--;
				count--;
			}
		}
		else
		{
			count = 0;
		}
	}
	return length;
	*/
	int i = 0;
	for (int n : nums)
		if (i < 2 || n > nums[i - 2])
			nums[i++] = n;
	return i;
}

int main()
{
	int arr[11] = { 1,1,1,1,5,6,1,3,2,2,3 };

	vector<int> vec(arr, arr + 11);

	int a = removeDuplicates(vec);

	cout << a << endl;

	return 0;
}