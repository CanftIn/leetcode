class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < num.size(); ++i) {
            if (m.find(target - num[i]) != m.end())
                return {m[target - num[i]], i};

            m[num[i]] = i;
        }
        return {};
    }
};