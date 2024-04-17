class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total_sum = 0;
        int current_sum = 0;
        for(int i = 0;i<nums.size();i++) {
            total_sum+=i+1;
            current_sum+=nums[i];
        }
        return total_sum-current_sum;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = 0;
        for(int i = 0;i<nums.size();i++) {
            num = num^(i+1)^nums[i];
        }
        return num;
    }
};

/*
    3+1 = 4
    1+2+3 = 6

*/
