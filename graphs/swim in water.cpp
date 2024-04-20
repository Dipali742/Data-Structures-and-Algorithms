class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({grid[0][0], {0, 0}});
        vector<pair<int, int>>indices {
            {0, -1},
            {0, 1},
            {1, 0},
            {-1, 0}
        };
        while(!pq.empty()) {
            int t = pq.top().first;
            int row = pq.top().second.first;
            int column = pq.top().second.second;
            pq.pop();
            
            if(row == n-1 && column == n-1)
                return t;
            for(auto it: indices) {
                int r = row + it.first;
                int c = column + it.second;
                if(r >= 0 && c >= 0 && r < n && c < n && grid[r][c] != -1) {
                    pq.push({max(t, grid[r][c]), {r, c}});
                    grid[r][c] = -1;
                }
            }
        }
        return -1;
    }
};
