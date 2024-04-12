class Solution {
public:
    int lis_recursive(vector<int>& nums, int index, int prev_index) {
        if(index == nums.size()-1) {
            if(prev_index == -1 || nums[prev_index] < nums[index])
                return 1;
            return 0;
        }
            
        //take
        int take = 0;
        if(prev_index == -1 || nums[prev_index] < nums[index]) {
            take = 1 + lis_recursive(nums, index+1, index);
        }
        //not_take
        int not_take = lis_recursive(nums, index+1, prev_index);

        return max(take, not_take);
    }

    int lis_recursive_index_shift(vector<int>& nums, int index, int prev_index) {
        if(index == nums.size() + 1) 
            return 0;
        //take
        int take = 0;
        if((prev_index-1) == -1 || nums[prev_index-1] < nums[index-1]) {
            take = 1 + lis_recursive_index_shift(nums, index+1, index);
        }
        //not_take
        int not_take = lis_recursive_index_shift(nums, index+1, prev_index);

        return max(take, not_take);
    }

    int lis_memoization(vector<int>& nums, int index, int prev_index, vector<vector<int>>&dp) {
        if(index == nums.size()) {
            if((prev_index-1) == -1 || nums[prev_index-1] < nums[index-1]) 
                return 1;
            return 0;
        }

        if(dp[index][prev_index] != -1)
            return dp[index][prev_index];
        int take = 0;
        if((prev_index-1) == -1 || nums[prev_index-1] < nums[index-1]) {
            take = 1 + lis_recursive_index_shift(nums, index+1, index);
        }
        //not_take
        int not_take = lis_recursive_index_shift(nums, index+1, prev_index);

        return dp[index][prev_index] = max(take, not_take);        
    }

    int lis_tabulation(vector<int>& nums, vector<vector<int>>&dp) {
        int n = nums.size();
        for(int i = 0;i<=n;i++) {
            if(i == 0 || nums[i-1] < nums[n-1]) {
                dp[n][i] = 1;
            }
        }

        for(int index = n-1;index>0;index--) {
            for(int prev_index = n-2;prev_index>=0;prev_index--) {
                int take = 0;
                if(prev_index-1 == -1 || nums[prev_index-1] < nums[index-1]) {
                    take = 1 + dp[index+1][index];
                } 
                int not_take = dp[index+1][prev_index];
                dp[index][prev_index] = max(take, not_take);
            }
        }
        return dp[1][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1, 0));
        return lis_tabulation(nums, dp);
    }
};
