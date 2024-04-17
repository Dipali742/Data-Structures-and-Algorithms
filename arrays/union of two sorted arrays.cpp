vector < int > sortedArray(vector < int > a, vector < int > b) {
    vector<int>ans;
    int ia = 0;
    int ib = 0;
    int ians = -1;
    while(ia < a.size() && ib < b.size()) {
        if(a[ia] < b[ib]) {
            if(ians == -1 || ans[ians] != a[ia]) {
                ans.push_back(a[ia]);
                ians++;
            } 
            ia++;
        } else if(a[ia] > b[ib]) {
            if(ians == -1 || ans[ians] != b[ib]) {
                ans.push_back(b[ib]);
                ians++;
            } 
            ib++;
        } else {
            if(ians == -1 || ans[ians] != b[ib]) {
                ans.push_back(b[ib]);
                ians++;
            } 
            ia++;
            ib++;
        }
    }

    while(ia < a.size()) {
            if(ians == -1 || ans[ians] != a[ia]) {
                ans.push_back(a[ia]);
                ians++;
            }
            ia++;  
    }

     while(ib < b.size()) {
            if(ians == -1 || ans[ians] != b[ib]) {
                ans.push_back(b[ib]);
                ians++;
            }
            ib++;  
    }
    return ans;
}
