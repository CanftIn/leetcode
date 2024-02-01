class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return dp(coins, amount);
    }

    int dp(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        int res = INT_MAX;
        for (int coin : coins) {
            int sub_problem = dp(coins, amount - coin);
            if (sub_problem == -1) continue;
            res = min(res, sub_problem + 1);
        }
        return res == INT_MAX ? -1 : res;
    }
};