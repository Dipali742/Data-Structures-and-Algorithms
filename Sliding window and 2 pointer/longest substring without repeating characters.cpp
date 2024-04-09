/*
  T(N + N)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>frequency;
        int max_length = 0;
        int fast = 0;
        int slow = 0;
        int len = s.length();
        while(fast < len) {
                while(frequency[s[fast]] != 0) {
                    cout<<s[fast]<<" ";
                    if(frequency[s[slow]] >= 1)
                        frequency[s[slow]]--;
                    else
                        frequency[s[slow]] = 0;
                    slow++;
                }
            if(frequency[s[fast]] == 0) {
                frequency[s[fast]]++;
                max_length = max(max_length, fast-slow+1);
            } 
            fast++;
        }
        return max_length;
    }
};

/*
  T(n)
*/
int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>index;
        int max_length = 0;
        int fast = 0;
        int slow = 0;
        int len = s.length();
        while(fast < len) {
            if(index.find(s[fast]) != index.end() && index[s[fast]] >= slow) {
                slow = index[s[fast]] + 1;
            }
            index[s[fast]] = fast;
            max_length = max(max_length, fast-slow+1);
            fast++;
        }
        return max_length;
}
