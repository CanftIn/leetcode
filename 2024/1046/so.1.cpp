class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        int index = stones.size() - 1;
        for (int i = 0; i < stones.size() - 1; i++) {   // 最多比较 length - 1 次
            std::sort(stones.begin(), stones.end());    // 对石头重量进行排序
            if (stones[index - 1] == 0)                 // 如果次大的石头重量为0，说明最多只剩一块石头
                break;
            stones[index] -= stones[index - 1];          // 将最大和次大的石头进行碰撞，求差
            stones[index - 1] = 0;                      // 次大的石头被摧毁
        }
        return stones[index];                           // 返回最后剩余的石头重量
    }
};