class Solution {
public:

    void combination(vector<vector<int>>&ans, vector<int>&row,vector<int>& candidates, int target, int index) {
        if(target == 0)
        {  
            ans.push_back(row);
            return;
        }
        for(int i = index;i<candidates.size();i++) {
            if(i > index && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            row.push_back(candidates[i]);
            combination(ans, row, candidates, target-candidates[i], i+1);
            row.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>row;
        sort(candidates.begin(), candidates.end());
        combination(ans, row, candidates,target, 0);
        return ans;
    }
};
