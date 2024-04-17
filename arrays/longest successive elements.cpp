int longestSuccessiveElements(vector<int>&a) {
    int len = 1;
    int max_len = 1;
    sort(a.begin(), a.end());
    int current = a[0];
    for(int  i =1;i<a.size();i++) {
        if(a[i] != a[i-1] && abs(a[i] - a[i-1]) == 1) {
            len++;
            current = a[i];
        } else if(a[i] != a[i-1]){
            max_len = max(max_len, len);
            len = 1;
        }
    }
    max_len = max(max_len, len);
    return max_len;
}
