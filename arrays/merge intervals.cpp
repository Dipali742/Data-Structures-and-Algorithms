
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>>ans;
        for(int i = 0;i<intervals.size();i++) {
            if(intervals[i][0] > end) {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } 
            if(intervals[i][1] > end)
                end = intervals[i][1];
        }

        ans.push_back({start, end});
        return ans;
    }
};
