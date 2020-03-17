#include <iostream>
#include <vector>

using namespace std;
/*
//others solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};
*/

//my solution
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] >= target)
			{
				return i;
			}
			if (nums[i] < target && target <= nums[(i + 1) > (nums.size() - 1) ? (nums.size() - 1) : 0])
			{
				return i + 1;
			}
		}
		if (target > nums[nums.size() - 1])
		{
			return nums.size();
		}
	}
};

int main()
{
	int  v1[10] = { 1, 3, 5, 6 };
	std::vector<int> myvector(&v1[0], &v1[4]);

	Solution solution;
	std::cout << solution.searchInsert(myvector, 7) << std::endl;
	return 0;
}