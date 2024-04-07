class Solution {
public:
    bool wordBreak_helper(unordered_map<string, int>wordMap, string s, int index) {
        if(index >= s.length())
            return true;

        string temp = "";
        for(int i = index;i<s.size();i++) {
            temp+=s[i];
            if(wordMap.find(temp) != wordMap.end()) {
                if(wordBreak_helper(wordMap, s, i+1))
                    return true;
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int>wordMap;
        for(int i = 0;i<wordDict.size();i++) {
            wordMap[wordDict[i]]++;
        }
        return wordBreak_helper(wordMap, s, 0);
    }
};


/*
    DP - Memoization
*/
class Solution {
public:
    bool wordBreak_helper(unordered_map<string, int>wordMap, string s, int index, vector<int>&dp) {
        if(index >= s.length())
            return true;

        if(dp[index] != -1)
            return dp[index];
        string temp = "";
        for(int i = index;i<s.size();i++) {
            temp+=s[i];
            if(wordMap.find(temp) != wordMap.end()) {
                if(wordBreak_helper(wordMap, s, i+1, dp))
                    return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int>wordMap;
        for(int i = 0;i<wordDict.size();i++) {
            wordMap[wordDict[i]]++;
        }
        vector<int>dp(s.length(), -1);
        return wordBreak_helper(wordMap, s, 0, dp);
    }
};


/*
    DP - tabulation
*/

bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int>wordMap;
        for(int i = 0;i<wordDict.size();i++) {
            wordMap[wordDict[i]]++;
        }

        int n = s.length();
        vector<bool>dp(n+1, false);
        dp[n] = true;
        for(int i=n-1;i>=0;i--) {
            string temp = "";
            for(int j = i;j<n;j++) {
                temp+=s[j];
                if(wordMap.find(temp) != wordMap.end() && dp[j+1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
