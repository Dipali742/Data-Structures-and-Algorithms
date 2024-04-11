class Solution {
public:
    int recursive(string s, int start, int end, int n) {
        if(start > end)
            return 0;
        if(start == end)
            return 1;
        
        if(s[start] == s[end])
            return 2 + recursive(s, start+1, end-1, n);
        return max(recursive(s, start+1, end, n), recursive(s, start, end-1, n));
    }

    int memoization(string s, int start, int end, int n, vector<vector<int>>&dp) {
        if(start > end)
            return 0;
        if(start == end)
            return 1;
        if(dp[start][end] != -1)
            return dp[start][end];
        if(s[start] == s[end])
            return dp[start][end] = 2 + memoization(s, start+1, end-1, n, dp);
        return dp[start][end] = max(memoization(s, start+1, end, n, dp), memoization(s, start, end-1, n, dp));        
    }

    int tabulation(string s, int n, vector<vector<int>>&dp) {
        for(int i = 0;i<=n;i++) {
            for(int j=0;j<=n;j++) {
                if(i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                if(i > j) {
                    dp[i][j] = 0;
                    continue;
                }
            }
        }
        for(int start = n-1; start >= 0; start--) {
            for(int end = 1; end < n; end++) {
                if(start >= end)
                    continue;
                if(s[start] == s[end]) {
                    dp[start][end] = 2 + dp[start+1][end-1];
                } else {
                    dp[start][end] = max(dp[start+1][end], dp[start][end-1]);
                }
            }
        }
        return dp[0][n-1];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        // return recursive(s, 0, n-1, n);
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return tabulation(s, n, dp);
    }
};
