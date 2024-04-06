void parenthesis(vector<string>&ans, int opening, int closing, string current) {
    if(opening == 0 && closing == 0) {
        ans.push_back(current);
        return;
    }
    if(opening > 0)
        parenthesis(ans, opening-1,closing, current + "(");
    if(closing > opening && closing > 0)
        parenthesis(ans, opening, closing-1, current + ")");

}

vector<string> validParenthesis(int n){
    vector<string>ans;
    int opening = n;
    int closing = n;
    parenthesis(ans, opening, closing, "");
    return ans;
}
