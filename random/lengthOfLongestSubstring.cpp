class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>index;
        int max_length = 0;
        int l = 0;
        int r = 0;
        int n = s.length();
        while(r < n) {
            if(index.find(s[r]) == index.end() || index[s[r]] < l) {
                index[s[r]] = r;             
            } else {
                l = index[s[r]] + 1;
                index[s[r]] = r;
            }
            max_length = max(max_length, r - l + 1);
            r++;
        }
        return max_length;
    }
};
