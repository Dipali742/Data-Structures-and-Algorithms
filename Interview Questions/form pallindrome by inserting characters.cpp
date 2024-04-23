
class Solution{   
public:

    int lcs(string a, string b, int ia, int ib) {
        if(ia == 0 || ib == 0)
            return a[ia] == b[ib];
        
        int cnt = 0;
        if(a[ia] == b[ib])
            cnt = 1 + lcs(a, b, ia-1, ib-1);
        else
            cnt = max(lcs(a, b, ia-1, ib), lcs(a, b, ia, ib-1));
        return cnt;
    }
    
    int memoization(string a, string b, int ia, int ib, vector<vector<int>>&dp) {
        if(ia < 0 || ib < 0)
            return 0;
        if(dp[ia][ib] != -1)
            return dp[ia][ib];
        int cnt = 0;
        if(a[ia] == b[ib])
            cnt = 1 + memoization(a, b, ia-1, ib-1, dp);
        else
            cnt = max(memoization(a, b, ia-1, ib, dp), memoization(a, b, ia, ib-1, dp));
        return dp[ia][ib] = cnt;        
    }
    
    int tabulation(string text1, string text2, int n, int m) {
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                int equal = INT_MIN;
                int not_equal = INT_MIN;
                if(text1[i-1] == text2[j-1])
                    equal = 1 + dp[i-1][j-1];
                else
                    not_equal = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = max(equal, not_equal);
            }
        }
        return dp[n][m];
    }
    
    int findMinInsertions(string s){
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        int len = tabulation(s, reversed, s.length(), s.length());
        return s.length()-len;
    }
};
