class Solution{
  public:
  
    int lcs(string str1, string str2, int i1, int i2, vector<vector<int>>&dp) {
        
        if(i1 < 0 || i2 < 0)
            return 0;
        if(dp[i1][i2] != -1)
            return dp[i1][i2];
        //same
        if(str1[i1] == str2[i2]) {
           return dp[i1][i2] = (1 + lcs(str1, str2, i1-1, i2-1, dp));
        } else {
            return dp[i1][i2] = max(lcs(str1, str2, i1-1, i2, dp), lcs(str1, str2, i1, i2-1, dp));
        }
        
    }
    
    int countMin(string str){
        int n = str.length();
        string reversed_str = str;
        reverse(reversed_str.begin(), reversed_str.end());
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int len = lcs(reversed_str, str, n-1, n-1, dp);
        
        return n-len;
    }
};
