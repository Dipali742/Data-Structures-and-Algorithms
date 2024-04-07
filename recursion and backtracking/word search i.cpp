class Solution {
public:
    bool exist_helper(vector<vector<char>>& board, string word, int index, int row, int column, int m, int n) {
        
        if(index >= word.length())
            return true;
        
        if(row < 0 || row >= m || column < 0 || column >= n || board[row][column] == '-')
            return false;
        char ch = board[row][column];

        if(board[row][column] == word[index]) {
            index++;
            board[row][column] = '-';
        } else
            return false;
        
        //top
        bool top = exist_helper(board, word, index, row-1, column, m, n);

        //bottom
        bool bottom = exist_helper(board, word, index, row+1, column, m, n);

        //right
        bool right = exist_helper(board, word, index, row, column+1, m, n);

        //left
        bool left = exist_helper(board, word, index, row, column-1, m, n);

        board[row][column] = ch;

        return top || bottom || right || left;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        int index = 0;

        // First search the first character
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[index]) {
                    if (exist_helper(board, word, index, i, j, m, n))
                        return true;
                }
            }
        }

        return false;
    }
};
