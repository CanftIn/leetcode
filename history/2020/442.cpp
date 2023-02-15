class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.size() <= 0) {
            return nums;
        }
        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            return b < a;   
        });
        vector<int> rec;
        int ikey = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if (nums[i] == ikey) {
                rec.push_back(ikey);
            }
            else {
                ikey = nums[i];
            }
        }
        return rec;
    }
};