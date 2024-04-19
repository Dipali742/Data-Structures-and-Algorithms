class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int max_len = 0;
        for(int i =0;i<points.size();i++) {
            unordered_map<string, int>mp;
            for(int j = i+1;j<points.size();j++) {
                int xdiff = points[j][0] - points[i][0];
                int ydiff = points[j][1] - points[i][1];
                string key;
                if(xdiff == 0) {
                    key = "y_" + to_string(points[j][0]);
                } else if(ydiff == 0) {
                    key = "x_" + to_string(points[j][1]);
                } else
                    key = to_string((double)ydiff/xdiff);
                mp[key]++;
                max_len = max(max_len, mp[key]);
            }
        }
        return max_len + 1;
    }
};
