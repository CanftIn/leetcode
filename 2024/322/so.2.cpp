class Solution {
public:
    vector<int> memo;

    int dp(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (memo[amount] != -666) return memo[amount];

        int res = INT_MAX;
        for (int coin : coins) {
            int sub_problem = dp(coins, amount - coin);
            if (sub_problem == -1) continue;
            res = min(res, sub_problem + 1);            
        }
        memo[amount] = res == INT_MAX ? -1 : res;
        return memo[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        memo = vector<int>(amount + 1, -666);
        return dp(coins, amount);
    }
};