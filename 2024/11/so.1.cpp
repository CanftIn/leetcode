class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        for (int i = 0; i < height.size(); ++i) {
            int right = i + 1;
            while (right < height.size()) {
                int short_line = height[right] < height[i] ? height[right] : height[i];
                max_water = max((right - i) * short_line, max_water);
                right++;
            }
        }
        return max_water;
    }
};

// 超出时间
