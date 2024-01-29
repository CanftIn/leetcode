class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (auto x : nums) {
            if (x != 0)
                nums[idx++] = x;
        }
        for (; idx < nums.size(); ++idx) {
            nums[idx] = 0;
        }
    }
};