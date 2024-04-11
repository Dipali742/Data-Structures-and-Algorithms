int recursive(int n, int w, vector<int>&profit, vector<int>&weight, int index) {
    
    if(index == 0) {
        return (w/weight[0]) * profit[0];
    }

    //pick
    int pick  = 0;
    if(w >= weight[index])
        pick = profit[index] + recursive(n, w-weight[index], profit, weight, index);

    //not_pick
    int not_pick = recursive(n, w, profit, weight, index-1);

    return max(pick, not_pick);
}

int memoization(int n, int w, vector<int>&profit, vector<int>&weight, int index, vector<vector<int>>&dp) {
    
    if(index == 0)
        return (w/weight[0]) * profit[0];
    if(dp[index][w] != -1)
        return dp[index][w];

    //pick
    int pick = 0;
    if(w >= weight[index])
        pick = profit[index] + memoization(n, w-weight[index], profit, weight, index, dp);

    //not_pick
    int not_pick = memoization(n, w, profit, weight, index-1, dp);

    return dp[index][w] = max(pick, not_pick);    
}

int tabulation(int n, int w, vector<int>&profit, vector<int>&weight, vector<vector<int>>&dp) {
    for(int i = 0;i<=w;i++) {
        dp[0][i] = (i/weight[0]) * profit[0];
    }

    for(int i = 1;i<n;i++) {
        for(int j = 0;j<=w;j++) {
            if(j == 0) {
                dp[i][j] = 0;
                continue;
            }

            //pick
            int pick = 0;
            if(j >= weight[i])
                pick = profit[i] + dp[i][j-weight[i]];
            int not_pick = dp[i-1][j];
            dp[i][j] = max(pick, not_pick);
        }
    }
    return dp[n-1][w];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n, vector<int>(w+1, -1));
    return tabulation(n, w, profit, weight,  dp);
}
