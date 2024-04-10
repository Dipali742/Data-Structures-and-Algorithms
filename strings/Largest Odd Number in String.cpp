class Solution {
public:
    string largestOddNumber(string nums) {
        int i = nums.size()-1;
        bool flg = 0;
        for(;i>=0;i--) {
            if((nums[i]-'0') % 2 == 1)
            {
                flg = 1;
                break;
            }
        }
        if(flg) {
            return nums.substr(0, i+1);
        }
        return "";

    }
};
