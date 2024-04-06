/*
    bit manipulation
    Time complexity - O(2^n * n)
    Space complexity - O(1)
*/
vector<vector<int>> subsets(vector<int>& nums) {
   	int n = nums.size();
	vector<vector<int>>ans;
	for(int i=0;i<(1<<n);i++) {
		vector<int>row;
		for(int j=0;j<n;j++) {
			if(i & (1<<j))
				row.push_back(nums[j]);
		}
		ans.push_back(row);
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
