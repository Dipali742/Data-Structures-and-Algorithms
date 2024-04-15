class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>que;
        int m = grid.size();
        int n = grid[0].size();
        int total_oranges = 0;
        int days = 0;
        int cnt = 0;
        for(int i = 0; i < m;i++) {
            for(int j = 0; j < n ;j++) {
                if(grid[i][j] == 2)
                    que.push({i, j});
                if(grid[i][j] != 0)
                    total_oranges++;
            }
        }

        vector<pair<int, int>>indexes{
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };
        while(!que.empty()) {
           int sizeq = que.size();
           cnt+=sizeq;
           while(sizeq--) {
                pair<int, int>current = que.front();
                que.pop();
                for(int i = 0; i <= 3; i++) {
                    int row = current.first + indexes[i].first;
                    int column = current.second + indexes[i].second;
                    if(row < 0 || row >= m || column < 0 || column >= n || grid[row][column] != 1)
                        continue;
                    grid[row][column] = 2;
                    que.push({row, column});
                }
           }

           if(!que.empty())
            days++;
        }

        return total_oranges == cnt ? days : -1;
    }
};
