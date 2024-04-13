class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>distance(m, vector<int>(n, -1));
        queue<pair<pair<int, int>, int>>que;
        for(int i = 0; i<m ;i++) {
            for(int j = 0; j<n ;j++) {
                if(mat[i][j] == 0) {
                    que.push({{i, j}, 0});
                    distance[i][j] = 0;
                }    
            }
        }

        while(!que.empty()) {
            pair<pair<int, int>, int>front = que.front();
            que.pop();
            int current_row = front.first.first;
            int current_col = front.first.second;
            int steps = front.second;

            //up
            if(current_row-1 >= 0) {
                if(distance[current_row - 1][current_col] == -1) {
                    distance[current_row - 1][current_col] = steps + 1;
                    que.push({{current_row - 1, current_col}, steps + 1});
                }
            }

            //down
            if(current_row + 1 < m) {
                if(distance[current_row + 1][current_col] == -1) {
                    distance[current_row + 1][current_col] = steps + 1;
                    que.push({{current_row + 1, current_col}, steps + 1});
                }
            }

            //left
            if(current_col-1 >= 0) {
                if(distance[current_row][current_col - 1] == -1) {
                    distance[current_row][current_col - 1] = steps + 1;
                    que.push({{current_row, current_col - 1}, steps + 1});
                }
            }

            //right
            if(current_col + 1 < n) {
                if(distance[current_row][current_col + 1] == -1) {
                    distance[current_row][current_col + 1] = steps + 1;
                    que.push({{current_row, current_col + 1}, steps + 1});
                }
            }
        }
        return distance;
    }
};
