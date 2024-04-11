string recursive(string s1, string s2, int index1, int index2) {

    if(index1 == 0 || index2 == 0)
        return "";
    //equal
    string equal = "";
    if(s1[index1-1] == s2[index2-1])
        equal = recursive(s1, s2, index1-1, index2-1) + s1[index1-1];
    string not_equal = max(recursive(s1, s2, index1-1, index2), recursive(s1, s2, index1, index2-1));

    return max(equal, not_equal);
}

//shift indexes
string memoization(string s1, string s2, int index1, int index2, vector<vector<string>>&dp) {
    if(index1 == 0 || index2 == 0)
        return "";

    if(dp[index1][index2] != "")
        return dp[index1][index2];
    if(s1[index1-1] == s2[index2-1])
       return memoization(s1, s2, index1-1, index2-1, dp) + s1[index1-1];
    string one = memoization(s1, s2, index1-1, index2, dp);
    string two = memoization(s1, s2, index1, index2-1, dp);
    return dp[index1][index2] = one.length() > two.length() ? one : two;
}

string tabulation(string s1, string s2, vector<vector<string>>&dp, int n, int m) {
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + s1[i-1];
                continue;
            }

            string one = dp[i-1][j];
            string two = dp[i][j-1];
            dp[i][j] = one.length() > two.length() ? one : two;
        }
    }
    return dp[n][m];
}

string findLCS(int n, int m,string &s1, string &s2){
	// return recursive(s1, s2, n, m);	
    vector<vector<string>>dp(n+1, vector<string>(m+1, ""));
    return memoization(s1, s2, n, m, dp);
}
