class Solution {
public:
    int fib(int n) {
        int memo[n + 1];
        memset(memo, 0, sizeof(memo));
        return dp(memo, n);
    }

    int dp(int memo[], int n) {
        if (n == 0 || n == 1) return n;
        if (memo[n] != 0) return memo[n];
        memo[n] = dp(memo, n - 1) + dp(memo, n - 2);
        return memo[n];
    }
};