class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>>ans;
        for(int i =0;i<nums.size();i++) {
            for(int j =i+1;j<nums.size();j++) {
                long long current_sum = nums[i] + nums[j];
                int l = j+1;
                int r = nums.size()-1;
                long long new_target = target - current_sum;
                while(l < r) {
                    if(nums[l] + nums[r] > new_target)
                        r--;
                    else if(nums[l] + nums[r] < new_target)
                        l++;
                    else {
                        ans.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                }
            }
        }
        vector<vector<int>>ans1;
        for(auto it: ans)
            ans1.push_back(it);
        return ans1;
    }
};
