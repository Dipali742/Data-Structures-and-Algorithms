class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i = 31; i>=0 ;i--) {
            int set_bits = 0;
            for(int j=0;j<n;j++) {
                if((nums[j] >> i) & 1)
                    set_bits++;
            }
            if(set_bits % 3 != 0) {
                res =  ((1 << i) | res);
            }
        }
        return res;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //bucket sort - two buckets
        int ones = 0;
        int twos = 0;
        int n = nums.size();
        for(int i =0 ;i<nums.size();i++) {
            ones = (ones^nums[i])&~twos; //add into ones if it is not in twos
            twos = (twos^nums[i])&~ones; //add into twos if it is not in ones
        }
        return ones;
    }
};
