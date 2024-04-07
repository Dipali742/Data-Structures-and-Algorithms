class Solution {
public:

    bool isSafe(int row, int column, vector<string>&board) {
        int n = board.size();
        //same row
        for(int i=0;i<n;i++) {
            if(board[row][i]=='Q' && i != column)
                return false;
        }

        //same column
        for(int i=0;i<n;i++) {
            if(board[i][column]=='Q' && i != row)
                return false;
        }

        //diagonal
        for(int i=0;i<n;i++) {
            if(i+row < n && i+column < n && i+row >=0  && i+column >=0) {
                if(board[i+row][i+column]=='Q')
                    return false;
            } 
            if(row-i < n && i+column < n && row-i >=0  && i+column >=0) {
                if(board[row-i][i+column]=='Q')
                    return false;
            } 
            if(i+row < n && column-i < n && i+row >=0  && column-i >=0) {
                if(board[i+row][column-i]=='Q')
                    return false;
            } 
            if(row-i < n && column-i < n && row-i >=0  && column-i >=0) {
                if(board[row-i][column-i]=='Q')
                    return false;
            } 
        }
        return true;
    }

    void solve(vector<vector<string>>&ans, int n, int column, vector<string>&board) {
        if(column == n) {
            ans.push_back(board);
            return;
        }

        //try to place it in all rows
        for(int i=0;i<n;i++) {
            if(isSafe(i, column, board)) {
                board[i][column] = 'Q';
                solve(ans, n, column+1, board);
                board[i][column] = '.';
            } 
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string str = "";
        for(int i = 0;i<n;i++)
            str+='.';
        vector<string>board(n, str);
        solve(ans,  n, 0, board);
        return ans;
    }
};
