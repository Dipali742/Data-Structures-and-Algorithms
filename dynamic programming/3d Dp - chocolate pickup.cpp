#include <bits/stdc++.h> 

int recursive(vector<vector<int>> &grid, int r, int c, int Ac, int Bc, int row) {
    if(Ac >= c || Bc >= c || Ac < 0 || Bc < 0)
        return 0;

    //base condition
    if(row == r-1) {
        if(Ac == Bc)
            return grid[row][Ac];
        else
            return grid[row][Ac] + grid[row][Bc];
    }
    
   
    //trying out all combinations
    int maximum_chocolates = 0;
    for(int i = -1; i<=1;i++) {
        for(int j = -1;j<=1;j++) {
            int chocolates = 0;
            if(Ac == Bc)
                chocolates += grid[row][Ac];
            else
                chocolates += grid[row][Ac] + grid[row][Bc];
            chocolates += recursive(grid, r, c, Ac+i, Bc+j, row+1);
            maximum_chocolates = max(maximum_chocolates, chocolates);
        }
    }
    return maximum_chocolates;
}

int memoization(vector<vector<int>> &grid, int r, int c, int Ac, int Bc, int row, vector<vector<vector<int>>>&dp) {
   if(Ac >= c || Bc >= c || Ac < 0 || Bc < 0)
        return 0;

    //base condition
    if(row == r-1) {
        if(Ac == Bc)
            return grid[row][Ac];
        else
            return grid[row][Ac] + grid[row][Bc];
    }
    
    if(dp[row][Ac][Bc] != -1)
        return dp[row][Ac][Bc];
    //trying out all combinations
    int maximum_chocolates = 0;
    for(int i = -1; i<=1;i++) {
        for(int j = -1;j<=1;j++) {
            int chocolates = 0;
            if(Ac == Bc)
                chocolates += grid[row][Ac];
            else
                chocolates += grid[row][Ac] + grid[row][Bc];
            chocolates += memoization(grid, r, c, Ac+i, Bc+j, row+1, dp);
            maximum_chocolates = max(maximum_chocolates, chocolates);
        }
    }
    return dp[row][Ac][Bc] = maximum_chocolates;
}

int tabulation(vector<vector<int>> &grid, int r, int c) {
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    for(int i = 0;i<c;i++) {
        for(int j = 0;j<c;j++) {
            if(i == j) {
                dp[r-1][i][j] = grid[r-1][j];
            } else {
                dp[r-1][i][j] = grid[r-1][j] + grid[r-1][i];
            } 
        }
    }

    for(int row = r-2;row>=0;row--) {
        for(int Ac = 0; Ac<c;Ac++) {
            for(int Bc = 0;Bc<c;Bc++) {
                for(int i = -1; i<=1;i++) {
                    for(int j = -1;j<=1;j++) {
                        int chocolates = 0;
                        if(Ac == Bc)
                            chocolates += grid[row][Ac];
                        else
                            chocolates += grid[row][Ac] + grid[row][Bc];
                        chocolates += dp[row+1][Ac+i][Bc+j];
                        dp[row][Ac][Bc] = max(dp[row][Ac][Bc], chocolates);
                    }
                }
            }
        }
    }
    return dp[0][0][0];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return memoization(grid, r, c, 0, c-1, 0, dp);
}
