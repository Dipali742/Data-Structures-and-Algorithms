int recursive(int n, vector<vector<int>> &points, int index, int last_task, vector<vector<int>>&dp) {
    if(index == n)
        return 0;
    if(dp[index][last_task] != -1)
        return dp[index][last_task];
    int max_merit = 0;
    for(int i = 0;i<3;i++) {
        if(i != last_task) {
            int current = points[index][i] + recursive(n, points, index+1, i, dp);
            max_merit = max(current, max_merit);
        }
    }
    return dp[index][last_task] = max_merit;
}

int tabulation(int n, vector<vector<int>> &points) {
     vector<vector<int>>dp(n, vector<int>(4, -1));

    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            if(i != j) {
                dp[n-1][i] = max(dp[n-1][i],points[n-1][j]);
            }
        }
    }

    for(int day = n-2;day>=0;day--) {
        for(int task = 0;task<4;task++) {
            dp[day][task] = 0;
            for(int last = 0;last<3;last++) {
                if(last != task) {
                    dp[day][task] = max(dp[day][task], points[day][last] + dp[day+1][last]);
                }
            }
        }
    }
    return dp[0][3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n, vector<int>(4, -1));
    return tabulation(n, points);
}
