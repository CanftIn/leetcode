class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> times;
        for (int i = 0; i < nums.size(); ++i) {
            times[nums[i]]++;
        }
        return std::max_element(times.begin(), times.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        })->first;
    }
};