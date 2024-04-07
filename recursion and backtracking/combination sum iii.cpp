class Solution {
public:
     void combination(vector<vector<int>>&ans, int k, vector<int>&row, int target, int index) {
        if(index >= 9) {
            if(target == 0 && row.size() == k)
                ans.push_back(row);
            return;
        }

        
        //take
        if((index+1) <= target) {
            row.push_back(index+1);
            combination(ans, k, row, target - (index+1), index+1);
            row.pop_back();
        }

        //not_take
        combination(ans, k, row, target, index+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>row;
        combination(ans, k, row, n, 0);
        return ans;
    }
};
