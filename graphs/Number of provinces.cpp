class DisjointUnion {
private:
    vector<int>parent;
    vector<int>rank;
public:
    DisjointUnion(int n) {
        parent.resize(n);
        rank.resize(n);
        for(int i =0;i<n;i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if(parent[node] == node)
            return parent[node];
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int uparent_u = findUParent(u);
        int uparent_v = findUParent(v);
        if(uparent_u == uparent_v)
            return;
        if(rank[uparent_u] > rank[uparent_v]) {
            parent[uparent_v] = uparent_u;
        } else if(rank[uparent_u] < rank[uparent_v]){
            parent[uparent_u] = uparent_v;
        } else {
            parent[uparent_u] = uparent_v;
            rank[uparent_v]++;
        }
    }
};

class Solution {
public:
    // void dfs(vector<vector<int>>&isConnected, vector<int>&visited, int node) {
    //     if(visited[node] == 1)
    //         return;
    //     visited[node] = 1;
    //     for(int i = 0 ; i< isConnected[node].size();i++) {
    //         if(isConnected[node][i] && visited[i] == -1) {
    //             dfs(isConnected, visited, i);
    //         }
    //     }
    // }

    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     vector<int>visited(isConnected.size(), -1);
    //     int cnt = 0;
    //     for(int i = 0 ;i<isConnected.size();i++) {
    //         if(visited[i] != 1) {
    //             dfs(isConnected, visited, i);
    //             cnt++;
    //         }       
    //     }
    //     return cnt;
    // }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        DisjointUnion dsu(n);
        for(int i = 0; i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(isConnected[i][j] == 1) {
                   dsu.unionByRank(i, j);
                }
            }
        }
        for(int i =0;i<n;i++) {
            if(dsu.findUParent(i) == i)
                cnt++;
        }
        return cnt;
    }
};
