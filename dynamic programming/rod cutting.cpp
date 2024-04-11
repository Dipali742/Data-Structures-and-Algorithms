int recursive(vector<int> &price, int index, int rod_length) {
	if(rod_length == 0)
		return 0;
	if(index == 0) {
		return rod_length*price[0];
	}

	//cut
	int cut = INT_MIN;
	int new_length = index+1;
	if(new_length <= rod_length) {
		cut = price[index] + recursive(price, index, rod_length - new_length);
	}

	//not_cut
	int not_cut = 0;
	not_cut = recursive(price, index-1, rod_length);

	return max(cut, not_cut);
}

int memoization(vector<int> &price, int index, int rod_length, vector<vector<int>>&dp) {
	if(rod_length == 0)
		return 0;
	if(index == 0) {
		return rod_length*price[0];
	}

	if(dp[index][rod_length] != -1)
		return dp[index][rod_length];

	//cut
	int cut = INT_MIN;
	int new_length = index+1;
	if(new_length <= rod_length) {
		cut = price[index] + memoization(price, index, rod_length - new_length, dp);
	}

	//not_cut
	int not_cut = 0;
	not_cut = memoization(price, index-1, rod_length, dp);

	return dp[index][rod_length] = max(cut, not_cut);
}


int tabulation(vector<int> &price, int n, vector<vector<int>>&dp) {
	for(int i = 0;i<n;i++) {
		dp[i][0] = 0;
	}
	for(int i = 0;i<=n;i++) {
		dp[0][i] = i*price[0]; 
	}

	for(int i = 1;i<n;i++) {
		for(int rod_length = 1;rod_length<=n;rod_length++) {
				int cut = INT_MIN;
				int new_length = i+1;
				if(new_length <= rod_length) {
					cut = price[i] + dp[i][rod_length-new_length];
				}
				
				int not_cut = 0;
				not_cut = dp[i-1][rod_length];
				dp[i][rod_length] = max(cut, not_cut);
		}
	}
	return dp[n-1][n];
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1, -1));
	return tabulation(price, n, dp);
}
