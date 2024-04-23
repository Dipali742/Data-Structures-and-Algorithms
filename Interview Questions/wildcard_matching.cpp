class Solution {
  public:
    /*You are required to complete this method*/
    
    bool wildCard_matching(string pattern, string str, int ip, int is, vector<vector<int>>&dp) {
        if(is >= str.length() && ip >= pattern.length()) {
            return true;
        }
        
        if(is >= str.length()) {
            for(;ip<pattern.length();ip++) {
                if(pattern[ip] != '*')
                    return false;
            }
            return true;
        }
        
        
        if(ip >= pattern.length())
            return false;
            
        if(dp[ip][is] != -1) {
            return dp[ip][is];
        }
        
        
        bool ans = false;
        if(pattern[ip] == str[is] || pattern[ip] == '?') {
            ans = ans || wildCard_matching(pattern, str, ip + 1, is + 1, dp);
        } else {
            if(pattern[ip] == '*') {
                ans = ans || wildCard_matching(pattern, str, ip, is + 1, dp);
                if(!ans)
                    ans = ans || wildCard_matching(pattern, str, ip + 1, is, dp);
            }
        }
        
        return dp[ip][is] = ans;
    }
    int wildCard(string pattern, string str) {
        vector<vector<int>>dp(pattern.length(), vector<int>(str.length(), -1));
        return wildCard_matching(pattern, str, 0, 0, dp);
    }
};
