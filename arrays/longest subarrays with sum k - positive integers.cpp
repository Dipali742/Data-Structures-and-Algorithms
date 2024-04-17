int longestSubarrayWithSumK(vector<int> a, long long k) {

    int l = 0;
    int r = 0;
    long long max_sum = 0;
    int len = 0;
    while(r < a.size()) {
        max_sum+=a[r];
        while(l <= r && max_sum > k) {
                max_sum-=a[l];
                l++;
            }
       
        if(max_sum == k) {
            len = max(len, r-l+1);
        }
        r++;
    }
    return len;
}
