class Solution {
public:

/*
   

*/
    int coinChange_recursion(vector<int>& coins, int amount, int index) {
        //base condition
        if(index == 0) {
            if(amount%coins[0] == 0)
                return amount/coins[0];
            return 1e9;
        }

        //recursive calls
        //pick
        int pick = 1e9;
        if(amount >= coins[index]) {
            pick = 1 + coinChange_recursion(coins, amount - coins[index], index);
        }

        //not_pick
        int not_pick = coinChange_recursion(coins, amount, index-1);

        return min(pick, not_pick);
    }

    int coinChange_memoization(vector<int>& coins, int amount, int index, vector<vector<int>>&dp) {
        //base condition
        if(index == 0) {
            if(amount%coins[0] == 0)
                return amount/coins[0];
            return 1e9;
        }

        if(dp[index][amount] != -1)
            return dp[index][amount];

        //recursive calls
        //pick
        int pick = 1e9;
        if(amount >= coins[index]) {
            pick = 1 + coinChange_memoization(coins, amount - coins[index], index, dp);
        }

        //not_pick
        int not_pick = coinChange_memoization(coins, amount, index-1, dp);

        return dp[index][amount] = min(pick, not_pick);
    }

    int tabulation(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 1e9));
        for(int i = 0;i<=amount;i++) {
            if(i%coins[0] == 0)
                dp[0][i] = i/coins[0];
        }

        for(int i=1;i<n;i++) {
            for(int j = 1; j <= amount ; j++) {
                //pick
                int pick = 1e9;
                if(j >= coins[i])
                    pick = 1 + dp[i][j-coins[i]];

                //not_pick
                int not_pick = dp[i-1][j];

                dp[i][j] = min(pick, not_pick);
            }
        }

        return dp[n-1][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = tabulation(coins, amount);
        return ans == 1e9 ? -1 : ans;
    }
};
