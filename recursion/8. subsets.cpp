/*
    bit manipulation
    Time complexity - O(2^n * n)
    Space complexity - O(1)
*/
vector<vector<int>> subsets(vector<int>& s) {
       int n = s.size();
        vector<vector<int>>ans;
        ans.push_back({});
        for (int num = 0; num < (1 << n); num++) {
            vector<int> sub;
            for (int i = 0; i < n; i++) {
                //check if the ith bit is set or not
                if (num & (1 << i)) {
                    sub.push_back(s[i]);
                }
		    }
            if (sub.size() > 0) {
                ans.push_back(sub);
            }
	    }
	    return ans;
}

/*
    recursive - take or not_take
    Time complexity - O(2^n)
    Space complextiy - O(n)
*/

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
