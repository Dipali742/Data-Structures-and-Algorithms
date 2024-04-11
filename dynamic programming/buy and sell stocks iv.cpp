class Solution {
public:
    int max_profit_recursive(vector<int>& prices, int index, int buy, int cap) {
        if(cap == 0)
            return 0;
        if(index == prices.size())
            return 0;

        if(buy == 1) {
            return max(-prices[index] + max_profit_recursive(prices, index+1, !buy, cap), max_profit_recursive(prices, index+1, buy, cap));
        } else {
            return max(prices[index] + max_profit_recursive(prices, index+1, !buy, cap-1), max_profit_recursive(prices, index+1, buy, cap));
        }
    }

    int max_profit_memoization(vector<int>& prices, int index, int buy, int cap, vector<vector<vector<int>>>&dp) {
        if(cap == 0)
            return 0;
        if(index == prices.size())
            return 0;
        if(dp[index][buy][cap] != -1)
            return dp[index][buy][cap];
        if(buy == 1) {
            return dp[index][buy][cap] = max(-prices[index] + max_profit_recursive(prices, index+1, !buy, cap), max_profit_recursive(prices, index+1, buy, cap));
        } else {
            return dp[index][buy][cap] = max(prices[index] + max_profit_recursive(prices, index+1, !buy, cap-1), max_profit_recursive(prices, index+1, buy, cap));
        }
    }

    int max_profit_tabulation(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for(int index = n-1 ; index>=0;index--) {
            for(int buy = 0;buy<2;buy++) {
                for(int cap = 1;cap<=k;cap++) {
                    if(buy == 1) {
                        dp[index][buy][cap] = max(-prices[index] + dp[index+1][0][cap], dp[index+1][buy][cap]);
                    } else {
                        dp[index][buy][cap] = max(prices[index] + dp[index+1][1][cap-1], dp[index+1][buy][cap]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return max_profit_memoization(prices, 0, 1, k, dp);
        // return max_profit_recursive(prices, 0, 1, k);
        return max_profit_tabulation(prices, k);
    }
};
