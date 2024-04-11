class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int minn = prices[0];
        for(int i=1;i<prices.size();i++) {
            minn = min(prices[i], minn);
            max_profit = max(prices[i]-minn, max_profit);
        }
        return max_profit;
    }
};
