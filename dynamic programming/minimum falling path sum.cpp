class Solution {
public:
    int solve_recursive(vector<vector<int>>& matrix, int row, int index, int n, vector<vector<int>>&dp) {
        if(row == n-1 && index < n && index >= 0)
            return matrix[row][index];
        if(index < 0 || index >= n)
            return 1e9;

        if(dp[row][index] != -1)
            return dp[row][index];
        int left = matrix[row][index] + solve_recursive(matrix, row+1, index-1, n, dp);
        int right = matrix[row][index] + solve_recursive(matrix, row+1, index+1, n, dp);
        int bottom = matrix[row][index] + solve_recursive(matrix, row+1, index, n, dp);

        // cout<<left<<" "<<right<<" "<<bottom<<endl;
        return dp[row][index] = min(left, min(right, bottom));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // int ans = INT_MAX;
        // vector<vector<int>>dp(n, vector<int>(n, -1));
        // for(int i=0;i<n;i++) {
        //     ans = min(ans, solve_recursive(matrix, 0, i, n, dp));
        // }
        // return ans;
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int i=n-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(i == n-1) {
                    dp[i][j] = matrix[i][j];
                    continue;
                }
                int left = 1e9;
                int right = 1e9;
                int bottom = matrix[i][j] + dp[i+1][j];
                if(j-1 >= 0)
                    left =  matrix[i][j] + dp[i+1][j-1];
                if(j+1 < n)
                    right =  matrix[i][j] + dp[i+1][j+1];
                dp[i][j] = min(left, min(right, bottom));
            }
        }
        for(int i=0;i<n;i++)
            ans=min(dp[0][i], ans);
        return ans;
    }
};
