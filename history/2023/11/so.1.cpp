class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        long long ret = 0;
        while (i < j) {
            long long tmp = 0;
            if (height[i] < height[j]) {
                tmp = height[i] * (j - i);
                ++i;
            } else {
                tmp = height[j] * (j - i);
                --j;
            }
            ret = tmp > ret ? tmp : ret;
        }
        return ret;
    }
};