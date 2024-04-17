vector<int> superiorElements(vector<int>&a) {
    int n = a.size();
    int current_max = a[n-1];
    vector<int>ans;
    for(int i = n-2;i>=0;i--) {
        if(a[i] > current_max) {
            ans.push_back(current_max);
            current_max = a[i];
        }   
        
    }
    ans.push_back(current_max);
    return ans;
}
