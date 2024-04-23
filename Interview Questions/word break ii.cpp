class Solution{
public:
    void recursive(string s, int index, vector<string>&res, vector<string>row, unordered_set<string>&st) {
        
        if(index == s.size()) {
            string new_string = "";
            for(auto it : row) {
                new_string += it + " ";
            }
            new_string = new_string.substr(0, new_string.size()-1);
            res.push_back(new_string);
        }
        
        //recursive impl
        string current = "";
        for(int i = index;i<s.size();i++) {
            current += s[i];
            if(st.find(current) != st.end()) {
                row.push_back(current);
                recursive(s, i+1, res, row, st);
                row.pop_back();
            }
                
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_set<string>st(dict.begin(), dict.end());
        vector<string>res;
        vector<string>row;
        recursive(s, 0, res, row, st);
        return res;
    }
    
    
    /*
        
    
    */
};
