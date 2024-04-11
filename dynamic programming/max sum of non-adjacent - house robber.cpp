class Solution {
public:

    int recursive(vector<int>&nums, int index) {
        if(index == 0)
            return nums[0];
       
        int pick = nums[index] ;
        int not_pick = INT_MIN;

        //pick
        if(index-2 >= 0)
            pick += recursive(nums, index-2); 

        //not_pick
        if(index-1 >= 0)
            not_pick = recursive(nums, index-1);

        return max(pick, not_pick);
    }

    int tabulation(vector<int>&nums, vector<int>&dp) {
        dp[0] = nums[0];
        int n = nums.size();
        for(int i = 1;i<n;i++) {
            int pick = nums[i];
            int not_pick = INT_MIN;
            if(i-2 >= 0)
                pick += dp[i-2];
            not_pick = dp[i-1];
            dp[i] = max(pick, not_pick);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        // return recursive(nums, nums.size()-1);
        int n = nums.size();
        vector<int>dp(n, -1);
        return tabulation(nums, dp);
    }
};
