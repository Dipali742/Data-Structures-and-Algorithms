class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 1) {
                cnt++;
            } else {
                maxi=max(maxi, cnt);
                cnt = 0;
            }
        }

        return max(maxi, cnt);
    }

};
