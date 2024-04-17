class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        
    long long max_sum = 0;
    unordered_map<int, int>preSum;
    int n = a.size();
    int cnt = 0;
    for(int i =0;i<n;i++) {
        max_sum+=a[i];
        cnt+=preSum[max_sum-k];
        if(max_sum == k)
            cnt++;
        preSum[max_sum]++;
    }
    return cnt;
    }
};
