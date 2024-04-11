class Solution {
public:

/*

buy : 0 
buy => -profit + f(i+1, 1, cap)
not_buy => 0 + f(i+1, 0, cap)


sell : 1
sell => profit + f(i+1, 0, cap-1)
not_sell => 0 + f(i+1, 1, cap)

dp[day][buy/sell][cap]

day => n+1;
cap => 2+1;

base condition => cap(0) : 0, i(n) : 0

*/
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int day = n-1; day >= 0; day--) {
            for(int buy = 1; buy >=0 ; buy--) {
                for(int cap = 1; cap < 3 ; cap++) {
                    if(buy == 0) {
                        dp[day][buy][cap] = max(-prices[day] + dp[day+1][1][cap], dp[day+1][0][cap]);
                    } else {
                        dp[day][buy][cap] = max(prices[day] + dp[day+1][0][cap-1], dp[day+1][1][cap]);
                    }
                }
            }
        }

        return dp[0][0][2];
    }


};
