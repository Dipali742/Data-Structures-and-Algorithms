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
