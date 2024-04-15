class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>>que;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0;j<n;j++) {
                if(i == 0 || j == 0 || j == n-1 || i == m-1) {
                    if(board[i][j] == 'O') {
                        que.push({i, j});
                        board[i][j] = '1';
                    }
                }
            }
        }

        vector<pair<int, int>>indexes{
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };  

        while(!que.empty()) {
            pair<int, int>current = que.front();
            que.pop();
            for(int i = 0; i <= 3 ;i++) {
                int row = current.first + indexes[i].first;
                int column = current.second + indexes[i].second;
                if(row < 0 || row >= m || column < 0 || column >= n)
                    continue;
                if(board[row][column] == 'O') {
                    que.push({row, column});
                    board[row][column] = '1';
                }
            }
        }

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0;j<n;j++) {
                if(board[i][j] == 'O' ) {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '1' ) {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
