class Solution {
public:
    void swap(vector<int>&nums, int start, int end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        while(start < n && end < n) {
            if(nums[start] == 0) { 
                if(nums[end] != 0) {
                   swap(nums, start, end);
                   start++;
                   end++;
                }
                else {
                    end++;
                }
            } else {
                start++;
                end++;
            }
        }
    }
};


void moveZeroes(vector<int>& nums) {
        int insertPos = 0;
        
        for (const int num : nums) {
            if (num != 0) {
                nums[insertPos] = num;
                insertPos++;
            }
        }
        
        while (insertPos < nums.size()) {
            nums[insertPos] = 0;
            insertPos++;
        }
    }
