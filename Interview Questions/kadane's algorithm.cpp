class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        long long sum = 0;
        long long max_sum = INT_MIN;
        for(int i = 0; i < n;i++) {
            sum += arr[i];
            max_sum = max(sum, max_sum);
            if(sum < 0) {
                sum = 0;
            } 
        }
        return max_sum;
    }
};
