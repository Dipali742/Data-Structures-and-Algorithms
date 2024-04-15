class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>>que;
        que.push({sr, sc});
        int initial_color = image[sr][sc];
        image[sr][sc] = color;
        vector<pair<int, int>>indexes{
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };  
        int m = image.size();
        int n = image[0].size();
        while(!que.empty()) {
            pair<int, int>current = que.front();
            que.pop();
            for(int i = 0; i <= 3; i++) {
                int row = current.first + indexes[i].first;
                int column = current.second + indexes[i].second;
                if(row < 0 || row >= m || column < 0 || column >= n)
                    continue;
                if(image[row][column] != initial_color || image[row][column] == color)
                    continue;
                image[row][column] = color;
                que.push({row, column});
            }
        }
        return image;
    }
};
