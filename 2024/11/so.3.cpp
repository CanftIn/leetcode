class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                res = max(res, (right - left) * height[left]);
                left++;
            } else {
                res = max(res, (right - left) * height[right]);
                right--;
            }
        }
        return res;
    }
};
