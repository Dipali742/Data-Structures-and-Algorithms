class Solution {
public:
    bool isPallindrome(string str) {
        int start = 0;
        int end = str.length()-1;
        while(start < end) {
            if(str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void partition_helper(vector<vector<string>>&ans, vector<string>row, string s, int index) {
        if(index == s.length()) {
            ans.push_back(row);
            return;
        }
        string str = "";
        for(int i=index;i<s.length();i++) {
            str+=s[i];
             if(isPallindrome(str)) {
                row.push_back(str);
                partition_helper(ans, row, s, i+1);
                row.pop_back();
             }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>row;
        partition_helper(ans, row, s, 0);
        return ans;
    }
};
