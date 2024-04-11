class Solution {
public:
    int recursive(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j) {
        if(i == m-1 && j == n-1 && obstacleGrid[i][j] != 1)
            return 1;
        if(i >= m || j >= n)
            return 0;
        if(obstacleGrid[i][j] == 1)
            return 0;   
        //down
        int down = recursive(obstacleGrid, m, n, i+1, j);

        //right
        int right = recursive(obstacleGrid, m, n, i, j+1);

        return down + right;
    } 

int memoization(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j, vector<vector<int>>&dp) {
        if(i == m-1 && j == n-1 && obstacleGrid[i][j] != 1)
            return 1;
        if(i >=m || j >= n)
            return 0;
        if(obstacleGrid[i][j] == 1)
            return 0;   
        if(dp[i][j] != -1)
            return dp[i][j];
        //down
        int down = memoization(obstacleGrid, m, n, i+1, j, dp);

        //right
        int right = memoization(obstacleGrid, m, n, i, j+1, dp);

        return dp[i][j] = down + right;
    }

    int tabulation(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<long long>>&dp) {
        dp[m-1][n-1] = 1;
        for(int i = m-1; i>= 0; i--) {
            for(int j = n-1;j>=0;j--) {
                if((i == m-1 && j == n-1 ) || obstacleGrid[i][j] == 1) {
                    dp[i][j] = !obstacleGrid[i][j];
                    continue;
                }
                //down
                long long down = 0;
                if(i + 1 < m) {
                    down = dp[i+1][j];
                }

                //right
                long long right = 0;
                if(j+1 < n) {
                    right = dp[i][j+1];
                }

                dp[i][j] = down+right;
            }
        }
        return dp[0][0];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>>dp(m, vector<long long>(n, 0));
        return tabulation(obstacleGrid, obstacleGrid.size(), obstacleGrid[0].size(), dp);
    }
};
