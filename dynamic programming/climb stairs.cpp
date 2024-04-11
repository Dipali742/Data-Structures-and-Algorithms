class Solution {
public:

    int recursion(int n) {
        if(n == 0)
            return 1;
        if(n < 0)
            return 0;
        int one = recursion(n-1);
        int two = recursion(n-2);
        return one + two;
    }

    int memoization(int n, vector<int>&dp) {
        if(n == 0)
            return 1;
        if(n < 0)
            return 0;
        if(dp[n] != -1)
            return dp[n];
        int one = memoization(n-1, dp);
        int two = memoization(n-2, dp);
        return dp[n] = one + two;
    }

    int tabulation(int n, vector<int>&dp) {
       dp[0] = 1;
       dp[1] = 1;
       for(int i = 2;i<=n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
       }
       return dp[n];
    }

    int space_optimization(int n) {
       int first = 1;
       int second = 1;
       int ans = 1;
       for(int i = 2;i<=n;i++) {
            ans = first + second;
            first = second;
            second = ans;
       }
       return ans;
    }

    int climbStairs(int n) {
       vector<int>dp(n+1, -1);
       return memoization(n, dp);
    }
};
