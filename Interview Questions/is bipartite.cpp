class Solution {
public:

    bool dfs(vector<vector<int>>& graph, vector<int>&visited, int node, int c) {
        visited[node] = c;
        for(auto it : graph[node]) {
                int current = it;
                if(visited[current] == c)
                    return false;
                if(visited[current] == -1)
                    if(!dfs(graph, visited, current, !c))
                        return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>visited(graph.size(), -1);
        for(int i = 0; i<graph.size();i++)
            if(visited[i] == -1 && !dfs(graph, visited, i, 0))
                return false;
        return true;
    }
};
