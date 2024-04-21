class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            xorr= xorr^nums[i];
        }
        int rightmost = (xorr & xorr-1) ^ xorr;
        int bucket1 = 0;
        int bucket2 = 0;
        for(int i = 0; i< n;i++) {
            if(rightmost & nums[i]) {
                bucket1 = bucket1^nums[i];
            } else {
                bucket2 = bucket2^nums[i];
            }
        }
        return {bucket1, bucket2};
    }
};
