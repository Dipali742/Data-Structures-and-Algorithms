class Solution {
public:

    void combinations(vector<string>&ans, string &digits, unordered_map<int, string>&mp, int index, string row) {

        if(index == digits.size() && row.length() != 0)
            ans.push_back(row);
        string possibleLetters = mp[digits[index]-'0'];
        for(int i = 0;i<possibleLetters.length();i++) {
            combinations(ans,digits, mp, index+1, row+possibleLetters[i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int, string>mp{
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };
        vector<string>ans;
        if(digits.empty())
            return ans;
        string row;
        combinations(ans, digits, mp, 0, row);
        return ans;        
    }
};
