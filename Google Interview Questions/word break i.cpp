class Solution
{
public:
    bool word_break_recursive(int n, string s, unordered_set<string> &dictionary, int index, vector<int>&dp) {
        if(index == n) {
            return true;
        }
        
        if(dp[index] != -1)
            return dp[index];
        
        string current = "";
        for(int i = index; i<n; i++) {
            current += s[i];
            if(dictionary.find(current) != dictionary.end()) {
                if(word_break_recursive(n, s, dictionary, i+1, dp)) {
                    return true;
                }
            }
        }
        
        return dp[index] = false;
    }
    
    int wordBreak(int n, string s, vector<string> &dictionary_arr) {
        unordered_set<string>dictionary;
        for(auto it: dictionary_arr) {
            dictionary.insert(it);
        }
        
        vector<int>dp(s.length(), -1);
        return word_break_recursive(s.length(), s, dictionary, 0, dp);
    }
}; 
