class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        stk.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(stk.empty())
                stk.push(s[i]);
            else
            {
                char ch=stk.top();
                if(s[i]=='{' || s[i]=='[' || s[i]=='(')
                    stk.push(s[i]);
                else if((s[i]=='}' && ch=='{') || (s[i]==']' && ch=='[') || (s[i]==')' && ch=='('))
                    stk.pop();
                else
                    return false;
            }
        }
        if(stk.size()==0)
            return true;
        else
             return false;
    }
};
