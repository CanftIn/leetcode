class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (auto i : nums2) {
            if (nums_set.find(i) != nums_set.end()) {
                result_set.insert(i);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
