#include <bits/stdc++.h> 

int recursive(vector<int> weight, vector<int> value, int n, int maxWeight, int index) {
	if(maxWeight == 0)
		return 0;

	if(index == 0) {
		if(maxWeight >= weight[index])
			return value[0];
		return 0;
	}

	//pick
	int pick = 0;
	if(maxWeight >= weight[index])
		pick = value[index] + recursive(weight, value, n, maxWeight-weight[index], index-1);
	
	int not_pick = recursive(weight, value, n, maxWeight, index-1);

	return max(pick, not_pick);
}

int memoization(vector<int> weight, vector<int> value, int n, int maxWeight, int index, vector<vector<int>>&dp) {
	if(maxWeight == 0)
		return 0;

	if(index == 0) {
		if(maxWeight >= weight[index])
			return value[0];
		return 0;
	}

	if(dp[index][maxWeight] != -1) {
		return dp[index][maxWeight];
	}
	//pick
	int pick = 0;
	if(maxWeight >= weight[index])
		pick = value[index] + memoization(weight, value, n, maxWeight-weight[index], index-1, dp);
	
	int not_pick = memoization(weight, value, n, maxWeight, index-1, dp);

	return dp[index][maxWeight] = max(pick, not_pick);
}

int tabulation(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>>dp(n, vector<int>(maxWeight+1, 0));
	//base
	for (int wt = weight[0]; wt <= maxWeight; wt++) {
        dp[0][wt] = value[0];
    }

	for(int i = 1;i<n;i++) {
		for(int wt = 1; wt<=maxWeight;wt++) {
			//pick
			int pick = 0;
			if(wt >= weight[i]) {
				pick = value[i] + dp[i-1][wt-weight[i]];
			}

			//not_pick
			int not_pick = dp[i-1][wt];

			dp[i][wt] = max(pick, not_pick);
		}
	}
	return dp[n-1][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	
	return tabulation(weight, value, n, maxWeight);
}
