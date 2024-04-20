class Solution{
    public:
    /*
    left, right
    left = min(opponent(left+2, right), o(left+1, right-1)
    
    */
    
    long long recursive(int arr[], int n, int left, int right, vector<vector<int>>&dp) {
        if(left > right)
            return 0;
        if(dp[left][right] != -1)
            return dp[left][right];
        //choose left
        long long left_ = arr[left] + min(recursive(arr, n, left+2, right, dp), recursive(arr, n, left+1, right-1, dp));
        
        //choose right
        long long right_ = arr[right] + min(recursive(arr, n, left+1, right-1, dp), recursive(arr, n, left, right-2, dp));
        return dp[left][right] = max(left_, right_);
    }
    

    long long maximumAmount(int n, int arr[]){
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        
        for(int i = 0; i < n; ++i) {
            dp[i][i] = arr[i];
        }
        
        for(int len = 2; len <= n; ++len) {
            for(int left = 0; left <= n - len; ++left) {
                int right = left + len - 1;
                long long leftChoice = arr[left];
                long long leftAddOn = 0;
                if(left + 2 <= right) {
                    //opponent chooses left
                    leftAddOn =  dp[left+2][right] > 0 ? dp[left+2][right] : 0;
                }
                if(left + 1 <= right-1) {
                    //opponent chooses right
                    leftAddOn = min(leftAddOn, dp[left+1][right-1]);
                }
                leftChoice += leftAddOn;
                
                
                long long rightChoice = arr[right];
                long long rightAddOn = 0;
                if(left + 1 <= right - 1) {
                    //opponent chooses left
                    rightAddOn = dp[left + 1][right - 1] > 0 ? dp[left + 1][right - 1] : 0;
                }
                if(left <= right - 2) {
                    //opponent chooses right
                    rightAddOn = min(rightAddOn, dp[left][right - 2]);
                }
                rightChoice += rightAddOn;
                dp[left][right] = max(leftChoice, rightChoice);
            }
        }
        
        return dp[0][n - 1];
    }

};
