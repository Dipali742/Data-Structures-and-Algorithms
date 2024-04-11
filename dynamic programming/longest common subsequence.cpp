class Solution {
public:
    int recursive(string text1, string text2, int index1, int index2) {

        if(index1 < 0 || index2 < 0) {
            return 0;
        }
        //equal
        int equal = INT_MIN;
        int not_equal = INT_MIN;
        if(text1[index1] == text2[index2])
            equal = 1 + recursive(text1, text2, index1-1, index2-1);
        else {
            not_equal = max(recursive(text1, text2, index1-1, index2), recursive(text1, text2, index1, index2-1));
        }
        
        return max(equal, not_equal);
    }

    //shift indexes
    int memoization(string text1, string text2, int index1, int index2, vector<vector<int>>&dp) {
        if(index1 == 0 || index2 == 0)
            return 0;

        if(dp[index1][index2] != -1)
            return dp[index1][index2];

        //equal
        int equal = INT_MIN;
        int not_equal = INT_MIN;
        if(text1[index1-1] == text2[index2-1]) {
            equal = 1 + memoization(text1, text2, index1-1, index2-1, dp);
        } else {
            not_equal = max(memoization(text1, text2, index1-1, index2, dp), memoization(text1, text2, index1, index2-1, dp));
        }

        return dp[index1][index2] = max(equal, not_equal);
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

    int longestCommonSubsequence(string text1, string text2) {
        // return recursive(text1, text2, text1.size()-1, text2.size()-1);
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        // return memoization(text1, text2, n, m, dp);
        return tabulation(text1, text2, n, m);
    }
};
