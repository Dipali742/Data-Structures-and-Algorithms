class Solution {
public:

/*

buy : 0
buy => -profit + f(day+1, 1)
not_buy => 0 + f(day+1, 0)

sell : 1
sell => profit + f(day + 2, 0)
not_sell => 0 + f(day+1, 1)

f(0, 0)

*/
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<vector<int>>dp(n+1, vector<int>(2, 0));

       for(int day = n-1; day>=0 ;day--) {
        for(int buy = 1; buy>=0 ;buy--) {
            if(buy == 0) {
                dp[day][buy] = max(-prices[day] + dp[day+1][1], dp[day+1][0]);
            } else {
                if(day+2 <= n)
                    dp[day][buy] = max(prices[day] + dp[day+2][0], dp[day+1][1]);
                else
                    dp[day][buy] = max(prices[day], dp[day+1][1]);
            }
         }
       }

       return dp[0][0];
    }
};
