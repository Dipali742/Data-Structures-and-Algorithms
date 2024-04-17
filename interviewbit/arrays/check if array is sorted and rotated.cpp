class Solution {
public:
    bool check(vector<int>& nums) {
        int flg = 0;
        for(int i = 1; i< nums.size();i++) {
            if(nums[i] < nums[i-1]) 
                flg++;
            if(flg > 1)
                return false;
        }

        if(nums[0] < nums[nums.size()-1] && flg == 1)
            return false;
        return true;
    }
};
