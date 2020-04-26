class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        if (nums.size() <= 0) {
            return -1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0 || nums[i] > nums.size() - 1) {
                return -1;
            }
        }
        vector<int> temp = nums;
        std::sort(temp.begin(), temp.end(), [](int a, int b) {
            return b < a;   
        });
        vector<int> rec;
        int ikey = temp[0];
        for(int i = 1; i < temp.size(); ++i) {
            if (temp[i] == ikey) {
                rec.push_back(ikey);
            }
            else {
                ikey = temp[i];
            }
        }
        if (rec.size() == 0)
            return 0;
        else
            return rec.front();
    }
};


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            while(i != nums[i]) {
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return 0;
    }
};


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(++m[nums[i]]>1) return nums[i];
        }
        return 0;
    }
};