class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre_product = 1;
        int suff_product = 1;
        int ans = INT_MIN;
        for(int i = 0;i<n;i++) {
            if(pre_product == 0) {
                pre_product = 1;
            }
            if(suff_product == 0) {
                suff_product = 1;
            }
            pre_product*=nums[i];
            suff_product*=nums[n-i-1];
            ans = max(ans, max(pre_product, suff_product));
        }
        return ans;
    }
};
