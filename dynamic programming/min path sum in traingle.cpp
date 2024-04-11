class Solution {
public:
    int recursive(vector<vector<int>>& triangle, int row, int column, vector<vector<int>>&dp) {
        if(row == triangle.size()-1)
            return triangle[row][column];
        if(dp[row][column] != -1)
            return dp[row][column];
        //i
        int first = triangle[row][column] + recursive(triangle, row+1, column, dp);

        //i+1
        int second = triangle[row][column] + recursive(triangle, row+1, column+1, dp);

        return dp[row][column] = min(first, second);
    }

    int tabulation(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        //base
        for(int i=0; i<triangle[n-1].size(); i++) {
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i = n-2;i>=0;i--) {
          for(int j = 0 ; j < triangle[i].size();j++) {
              int first = triangle[i][j] + dp[i+1][j];
              int second = triangle[i][j] + dp[i+1][j+1];
              dp[i][j] = min(first, second);
          }
        }
        return dp[0][0];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(), vector<int>(triangle.size(), -1));
        return tabulation(triangle);
    }
};
