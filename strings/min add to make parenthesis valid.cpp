class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening = 0;
        int cnt = 0;
        for(int i = 0;i<s.length();i++) {
            if(s[i] == '(')
                opening++;
            else {
                if(opening == 0)
                    cnt++;
                else
                    opening--;
            }

        }
        return cnt + opening;
    }
};


class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>stk;
        int cnt = 0;
        for(int i = 0;i<s.length();i++) {
            if(s[i] == '(')
                stk.push('(');
            else {
                if(stk.empty())
                    cnt++;
                else
                    stk.pop();
            }

        }
        return cnt + stk.size();
    }
};
