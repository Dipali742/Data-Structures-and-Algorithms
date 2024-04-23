class Solution {
public:
    bool isSafe(int r, int c, int m, int n)  {
        return r < m && r >= 0 && c < n && c >= 0;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        grid[r][c] = '2';
        vector<vector<int>>directions {
            {-1, 0},
            {1, 0},
            {0, 1},
            {0, -1}
        };

        for(int i = 0; i < 4; i++) {
            int row = r + directions[i][0];
            int column = c + directions[i][1];
            if(isSafe(row, column, grid.size(), grid[0].size()) && grid[row][column] == '1') {
                dfs(grid, row, column);
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int number_of_islands = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    number_of_islands++;
                }
            }
        }
        return number_of_islands;
    }
};
