class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> s;
        for(int i = 0; i < n-2; i++) {
            int a = nums[i];
            int l = i + 1;
            int r = n - 1;
            while(l < r) {
                int sum = a + nums[l] + nums[r];
                if(sum > 0) {
                    r--;
                } else if(sum < 0) {
                    l++;
                } else {
                    s.insert({a, nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }
        vector<vector<int>>ans(s.begin(), s.end());
        return ans;
    }
};
