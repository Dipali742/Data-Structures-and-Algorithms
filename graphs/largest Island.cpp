class DSU {
private:
    vector<int>parent;
    vector<int>size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i<n;i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if(parent[node] == node)
            return node;
        return findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int uparent_u = findUParent(u);
        int uparent_v = findUParent(v);
        if(uparent_u == uparent_v)
            return;
        if(size[uparent_v] > size[uparent_u]) {
            parent[uparent_u] = uparent_v;
            size[uparent_v] += size[uparent_u];
        } else {
            parent[uparent_v] = uparent_u;
            size[uparent_u] += size[uparent_v]; 
        }
    }

    int getSize(int node) {
        return size[node];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);
        vector<pair<int, int>>indices{
            {0, -1},
            {0, 1},
            {1, 0},
            {-1, 0}
        };
        for(int i = 0; i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                   for(auto it : indices) {
                        int row = it.first + i;
                        int column = it.second + j;
                        if(row >= 0 && column >= 0 && row < n && column < n && grid[row][column] == 1) {
                            int node = i*n + j;
                            int adjNode = row*n + column;
                            ds.unionBySize(node, adjNode);
                        }
                   }
                }
            }
        }
        int max_area = 0;
        for(int i = 0; i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 0) {
                    unordered_map<int, int>mp;
                    int area = 0;
                    for(auto it : indices) {
                        int row = it.first + i;
                        int column = it.second + j;
                        if(row >= 0 && column >= 0 && row < n && column < n && grid[row][column] == 1) {
                            int node = row*n + column;
                            int uparent = ds.findUParent(node);
                            int size = ds.getSize(uparent);
                            mp[uparent] = size;
                        }
                    }

                    for(auto it : mp) {
                        area += it.second;
                    }
                    max_area = max(area+1, max_area);
                }
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            int si = ds.getSize(ds.findUParent(cellNo));
            max_area = max(max_area, si);
        }
        return max_area;
    }
};
