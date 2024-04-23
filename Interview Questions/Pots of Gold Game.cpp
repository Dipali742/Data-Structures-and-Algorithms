class Solution {
public:

    int max_coins(vector<int>&A, int n, int low, int high, vector<vector<int>>&dp) {
        if(low > high)
            return 0;
        
        if(dp[low][high] != -1) 
            return dp[low][high];
        int left = A[low] + min(max_coins(A, n, low + 2, high, dp), max_coins(A, n, low+1, high-1, dp));
        int right = A[high] + min(max_coins(A, n, low+1, high-1, dp), max_coins(A, n, low, high-2, dp));
        
        
        return dp[low][high] = max(left, right);
    }
    
    
    int maxCoins(vector<int>&A,int n)
    {
        vector<vector<int>>dp(n, vector<int>(n, -1));
	    return max_coins(A, n, 0, n-1, dp);
    }
};
