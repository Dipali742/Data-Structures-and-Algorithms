class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int indexBeforeLastMaxima;
        int numberToSwapWithIndex;
        bool possible = false;
        int i = n-1;
        for(;i>0;i--) {
            if(nums[i] > nums[i-1]) {
                indexBeforeLastMaxima = i-1;
                numberToSwapWithIndex = i;
                possible = true;
                break;
            }
        }
        if(!possible) {
            reverse(nums.begin(), nums.end());
            return;
        }         
        
        for(;i<n;i++) {
            if(nums[i] > nums[indexBeforeLastMaxima] && nums[numberToSwapWithIndex] >= nums[i])
                numberToSwapWithIndex = i;
        }
        swap(nums[indexBeforeLastMaxima], nums[numberToSwapWithIndex]);
        reverse(nums.begin()+indexBeforeLastMaxima+1, nums.end());
    }
};
