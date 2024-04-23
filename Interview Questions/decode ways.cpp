class Solution {
public:

    bool isSafe(string str) {
        if(str[0] == '0' || str.length() > 2)
            return false;
        long long no = stol(str);
        return no >= 1 && no <= 26;
    }

    int solve(string s, int index, vector<int>&dp) {
        if(index == s.length())
            return 1;
        if(dp[index] != -1)
            return dp[index];
        
        string str = "";
        int ways = 0;
        for(int i = index; i<s.length();i++) {
            str += s[i];
            if(isSafe(str)) {
                ways += solve(s, i + 1,dp); 
            } 
        } 
        return dp[index] = ways;
    }

    int numDecodings(string s) {
        int ways = 0;
        vector<int>dp(s.length(), -1);
        return solve(s, 0, dp);
    }
};
