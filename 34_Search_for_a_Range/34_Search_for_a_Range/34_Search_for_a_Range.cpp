#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) 
{
	vector<int> re;
	int count = 0;
	int i = 0;
	for (; i < nums.size(); ++i)
	{
		if (nums[i] == target)
		{
			re.push_back(i);
			count++;
		}
	}
	if (count == 0)
		return { -1, -1 };
	else if (count == 1 && i == 0)
		return { 0, 0 };
	else
		return re;
}

/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left_binary = 0;
        int right_binary = nums.size() - 1;
        int mid;
        int start = -1; //initailize as -1 
        int end = -1;
        vector<int> result;
        
        //Step1. Binary search for the target
        while(left_binary <= right_binary)
        {
            mid = (left_binary + right_binary) / 2;
            if(nums[mid] == target)
            {
                start = end = mid; //record the index
            }
            if(nums[mid] > target){right_binary = mid - 1;}
            else{left_binary = mid + 1;}
        }
        
        //Step2. search towards left and right
        while(start > 0 && nums[start - 1] == target){ --start;}
        while(end < nums.size() - 1 && nums[end + 1] == target){ ++end;} 
        
        result.push_back(start);
        result.push_back(end);
        
        return result;
      
    }

};
*/

int main()
{
	int num[] = { 5, 7, 7, 8, 8, 10 };
	vector<int> nums(&num[0], &num[5]);
	vector<int> re = searchRange(nums, 8);

	for (int i = 0; i < re.size(); ++i)
	{
		std::cout << re[i] << std::endl;
	}
	return 0;
}