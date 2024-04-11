class Solution {
public:
    int bestTime(vector<int>& prices, int index, int buy) {

        if(index == prices.size())
            return 0;
        if(buy) {
           return max(-prices[index] + bestTime(prices, index+1, !buy), bestTime(prices, index+1, buy));
        } else {
            return max(prices[index] + bestTime(prices, index+1, !buy), bestTime(prices, index+1, buy));
        }
    }
    
    int bestTime_memoization(vector<int>& prices, int index, int buy, vector<vector<int>>&dp) {
        if(index == prices.size())
            return 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];
        if(buy) {
           return dp[index][buy] = max(-prices[index] + bestTime_memoization(prices, index+1, !buy, dp), bestTime_memoization(prices, index+1, buy, dp));
        } else {
            return dp[index][buy] = max(prices[index] + bestTime_memoization(prices, index+1, !buy, dp), bestTime_memoization(prices, index+1, buy, dp));
        } 
    }

    int bestTime_tabulation(vector<int>& prices, vector<vector<int>>&dp) {
        int n = prices.size();
        for(int i = n-1;i>=0;i--) {
            for(int j = 0;j<2;j++) {
                if(j == 1) {
                    dp[i][j] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                } else {
                    dp[i][j] = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1, vector<int>(2, 0));
        return bestTime_tabulation(prices, dp);
    }
};
