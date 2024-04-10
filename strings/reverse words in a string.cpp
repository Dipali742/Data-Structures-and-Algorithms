class Solution {
public:
    string reverseWords(string s) {
        string ans;
        for(int i=0;i<s.size();i++) {
            string temp="";
            while(s[i] != ' ' && i<s.size()) {
                temp+=s[i];
                i++;
            }
            string temp1 = ans;
            if(temp != "" && ans != "")
                ans = temp+" "+temp1;
            else if(temp != "")
                ans = temp;
        }
        return ans;
    }
};
