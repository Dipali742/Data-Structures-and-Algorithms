#include <bits/stdc++.h> 

int recursion(int n, vector<int>&heights, int index) {
    if(index == 0)
        return 0;

    //one step
    int one = INT_MAX;
    if(index-1 >= 0)
        one = abs(heights[index] - heights[index-1]) + recursion(n, heights, index-1);

    //two step
    int two = INT_MAX;
    if(index-2 >= 0)
        two = abs(heights[index] - heights[index-2]) + recursion(n, heights, index-2);

    return min(one, two);
}

int memoization(int n, vector<int>&heights, int index, vector<int>&dp) {
    if(index == 0)
        return 0;

    if(dp[index] != -1)
        return dp[index];
    //one step
    int one = INT_MAX;
    if(index-1 >= 0)
        one = abs(heights[index] - heights[index-1]) + memoization(n, heights, index-1, dp);

    //two step
    int two = INT_MAX;
    if(index-2 >= 0)
        two = abs(heights[index] - heights[index-2]) + memoization(n, heights, index-2, dp);

    return dp[index] = min(one, two);
}

int tabulation(int n, vector<int>&heights, vector<int>&dp) {
    dp[0] = 0;
    dp[1] = abs(heights[1]-heights[0]);
    for(int i = 2;i<n;i++) {
        int one_step = abs(heights[i]-heights[i-1]) + dp[i-1];
        int two_step = abs(heights[i]-heights[i-2]) + dp[i-2];
        dp[i] = min(one_step, two_step);
    }
    return dp[n-1];
}

int space_optimization(int n, vector<int>&heights) {
    int first_prev = 0;
    int second_prev = abs(heights[1]-heights[0]);
    for(int i = 2;i<n;i++) {
        int one_step = abs(heights[i]-heights[i-1]) + second_prev;
        int two_step = abs(heights[i]-heights[i-2]) + first_prev;
        first_prev = second_prev;
        second_prev = min(one_step, two_step);
    }
    return second_prev;
}

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n, -1);

   return space_optimization(n, heights);
}
