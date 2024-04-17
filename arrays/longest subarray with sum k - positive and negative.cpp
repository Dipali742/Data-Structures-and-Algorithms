#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& a, int k){
    long long max_sum = 0;
    unordered_map<int, int>preSum;
    int n = a.size();
    int len = 0;
    for(int i =0;i<n;i++) {
        max_sum+=a[i];
        if(preSum.find(max_sum-k) != preSum.end()) {
            len = max(len, i - preSum[max_sum-k]);
        }

        if(max_sum == k)
            len = max(len, i+1);
        
        if(preSum.find(max_sum) == preSum.end()) {
            preSum[max_sum] = i;
        }
    }
    return len;
}
