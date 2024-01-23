class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        for (auto x : nums) {
            if (x != val)
                nums[idx++] = x;
        }
        return idx;
    }
};