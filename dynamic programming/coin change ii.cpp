class Solution {
public:

/*
   

*/
    int coinChange_recursion(vector<int>& coins, int amount, int index) {
        //base condition
        if(index == 0) {
            if(amount%coins[0] == 0)
                return 1;
            return 0;
        }
       
        //recursive calls
        //pick
        int pick = 0;
        if(amount >= coins[index]) {
            pick = coinChange_recursion(coins, amount - coins[index], index);
        }

        //not_pick
        int not_pick = coinChange_recursion(coins, amount, index-1);

        return pick + not_pick;
    }

    int coinChange_memoization(vector<int>& coins, int amount, int index, vector<vector<int>>&dp) {
        //base condition
        if(index == 0) {
            if(amount%coins[0] == 0)
                return 1;
            return 0;
        }
        if(dp[index][amount] != -1)
            return dp[index][amount];
        //recursive calls
        //pick
        int pick = 0;
        if(amount >= coins[index]) {
            pick = coinChange_memoization(coins, amount - coins[index], index, dp);
        }

        //not_pick
        int not_pick = coinChange_memoization(coins, amount, index-1, dp);

        return dp[index][amount] = pick + not_pick;
    }

    int tabulation(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0] == 0)
                dp[0][i] = 1;
        }

        for(int i=1;i<n;i++) {
            for(int j = 0; j <= amount ; j++) {
                //pick
                int pick = 0;
                if(j >= coins[i])
                    pick = dp[i][j-coins[i]];

                //not_pick
                int not_pick = dp[i-1][j];

                dp[i][j] = pick + not_pick;
            }
        }

        return dp[n-1][amount];
    }

    int change(int amount, vector<int>& coins) {
        int ans = coinChange_recursion(coins, amount, coins.size()-1);
        return ans == 1e9 ? -1 : ans;
    }
};
