class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int price : prices) {
            max_profit = max(max_profit, price - min_price);
            min_price = min(price, min_price);
        }
        return max_profit;
    }
};