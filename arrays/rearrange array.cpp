class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] >= 0)
                pos.push_back(nums[i]);
            else 
                neg.push_back(nums[i]);
        }
        vector<int>ans(n, 0);
        for(int i = 0;i<n/2;i++) {
            ans[2*i] = pos[i];
            ans[2*i+1] = neg[i];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);
        int posi = 0;
        int negi = 1;
        for(int i = 0;i<n;i++) {
            if(nums[i] >= 0) {
                ans[posi] = nums[i];
                posi+=2;
            } else {
                ans[negi] = nums[i];
                negi+=2;
            }
        }
        return ans;
    }
};
