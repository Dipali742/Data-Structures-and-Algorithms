vector<int> Solution::getRow(int A) {
    if(A == 0)
        return {1};
    vector<int>temp = getRow(A-1);
    vector<int>ans;
    ans.push_back(1);
    for(int i = 0 ; i<temp.size()-1;i++) {
        ans.push_back(temp[i]+temp[i+1]);
    }
    ans.push_back(1);
    return ans;
    
}


vector<int> Solution::getRow(int n) {
    vector <int> ans;
    int c = 1;
    for (int i = 1; i <= n+1; i++) {
        ans.push_back(c);
        c = c*(n+1-i) / i;
    }
    return ans;
}
