int recursion(int n, int k, vector<int> &height, int index) {
    if(index == 0)
        return 0;

     //recursive call
    int min_cost = INT_MAX;
    for(int i = 1;i<=k;i++) {
        if(index - i >= 0)
            min_cost = min(min_cost, abs(height[index] - height[index - i]) + recursion(n,k, height,index-i));
    }
    return min_cost;
}

int memoization(int n, int k, vector<int> &height, int index, vector<int>&dp) {
    if(index == 0)
        return 0;

    if(dp[index] != -1)
        return dp[index];

     //recursive call
    int min_cost = INT_MAX;
    for(int i = 1;i<=k;i++) {
        if(index - i >= 0)
            min_cost = min(min_cost, abs(height[index] - height[index - i]) + memoization(n,k, height,index-i, dp));
    }
    return dp[index] = min_cost;
}

int tabulation(int n, int k, vector<int> &height, vector<int>&dp) {
    dp[0] = 0;

    for(int index = 1;index<n; index++) {
        for(int i = 1;i<=k;i++) {
            if(index - i >= 0)
                dp[index] = min(dp[index], abs(height[index] - height[index - i]) + dp[index-i]);
        }
    }
    return dp[n-1];
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n, INT_MAX);
    return tabulation(n, k, height, dp);
}
