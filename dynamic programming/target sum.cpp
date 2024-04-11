#include <bits/stdc++.h> 

bool subset(int n, int k, vector<int> &arr, int index) {

    if(index == 0) {
        if(k == 0 || k == arr[0])
            return true;
        return false;
    }

    //pick
    bool pick = false;
    if(k >= arr[index]) 
        pick = subset(n, k-arr[index], arr, index-1);

    //not_pick
    bool not_pick = subset(n, k, arr, index-1);

    return pick || not_pick;
}

bool memoization(int n, int k, vector<int>&arr, int index, vector<vector<int>>&dp) {
    if(index == 0) {
        if(k == 0 || k == arr[0])
            return true;
        return false;
    }
    if(dp[index][k] != -1)
        return dp[index][k];
    //pick
    bool pick = false;
    if(k >= arr[index]) 
        pick = memoization(n, k-arr[index], arr, index-1, dp);

    //not_pick
    bool not_pick = memoization(n, k, arr, index-1, dp);

    return dp[index][k] = (pick || not_pick);
}

bool tabulation(int n, int k, vector<int>&arr) {
    vector<vector<int>>dp(n, vector<int>(k+1, -1));
    dp[0][0] = 1;
    for(int i = 0;i<n;i++) {
        for(int j=0;j<=k;j++) {
            if(j == 0) {
                dp[i][0] = 1;
                continue;
            }
            if(i == 0) {
                if(arr[i] == j)
                    dp[0][j] = 1;
                else
                    dp[0][j] = 0;
                continue;
            }
           
            bool pick = false;
            if(j >= arr[i]) 
                pick = dp[i-1][j-arr[i]];

            //not_pick
            bool not_pick = dp[i-1][j];
            dp[i][j] = pick || not_pick;       
        }
    }
    return dp[n-1][k];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return tabulation(n, k, arr);
}
