class Solution {
public:

    void generateSubsets(vector<vector<int>>&ans,vector<int>row,vector<int>nums,int n,int index) {
        if(index == n) {
            ans.push_back(row);
            return;
        }
        
        //take
        row.push_back(nums[index]);
        generateSubsets(ans, row, nums, n, index+1);

        //not-take
        row.pop_back();        
        generateSubsets(ans, row, nums, n, index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>row;
        int n = nums.size();
        generateSubsets(ans, row, nums, n, 0);
        return ans;
    }
};
