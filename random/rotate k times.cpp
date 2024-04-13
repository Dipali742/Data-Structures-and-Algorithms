class Solution {
public:
    void reverse(vector<int>&nums, int start, int end) {
        while(start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size()-1;
        int n = nums.size();
        // while(k > n)
        //     k = k-n;

        k = k % n;
        reverse(nums, start, end);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};
