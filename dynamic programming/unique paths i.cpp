class Solution {
public:
    int recursive(int m, int n, int i, int j) {
        if(i == m-1 && j == n-1)
            return 1;
        if(i >= m || j >= n)
            return 0;
            
        //down
        int down = recursive(m, n, i+1, j);

        //right
        int right = recursive(m, n, i, j+1);

        return down + right;
    }

    int memoization(int m, int n, int i, int j, vector<vector<int>>&dp) {
        if(i == m-1 && j == n-1)
            return 1;
        if(i >=m || j >= n)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        //down
        int down = memoization(m, n, i+1, j, dp);

        //right
        int right = memoization(m, n, i, j+1, dp);

        return dp[i][j] = down + right;
    }

    int tabulation(int m, int n, vector<vector<int>>&dp) {
        dp[m-1][n-1] = 1;
        for(int i = m-1; i>= 0; i--) {
            for(int j = n-1;j>=0;j--) {
                //down
                int down = 0;
                if(i + 1 < m) {
                    down = dp[i+1][j];
                }

                //right
                int right = 0;
                if(j+1 < n) {
                    right = dp[i][j+1];
                }

                dp[i][j] = down+right;
            }
        }
        return dp[0][0];
    }

    int uniquePaths(int m, int n) {
        // return recursive(m, n, 0, 0);
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return memoization(m, n, 0, 0, dp);
    }
};
