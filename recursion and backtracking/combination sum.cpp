class Solution {
public:

    void combination(vector<vector<int>>&ans, int index, vector<int>&candidates, int target, vector<int>row) {
      
        if(index == candidates.size()) {
            if(target == 0)
                ans.push_back(row);
            return;
        }       
        
        //take
        if(candidates[index] <= target) {
            row.push_back(candidates[index]);
            combination(ans, index, candidates, target - candidates[index], row);
            row.pop_back();
        }
        
        //not_take
        combination(ans, index+1, candidates, target, row);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>row;
        combination(ans, 0, candidates, target, row);
        return ans;
    }
};
