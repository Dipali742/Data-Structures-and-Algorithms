class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
          int n = prices.size();
       vector<vector<int>>dp(n+1, vector<int>(2, 0));

       for(int day = n-1; day>=0 ;day--) {
        for(int buy = 1; buy>=0 ;buy--) {
            if(buy == 0) {
                dp[day][buy] = max(-prices[day] + dp[day+1][1], dp[day+1][0]);
            } else {
                dp[day][buy] = max(prices[day] + dp[day+1][0] - fee, dp[day+1][1]);
            }
         }
       }

       return dp[0][0];
    }
};
