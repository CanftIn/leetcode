class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, res = 0;
        while (i < j) {
            res = height[i] < height[j] ?
                max(res, (j - i) * height[i++]) :
                max(res, (j - i) * height[j--]);
        }
        return res;
    }
};
