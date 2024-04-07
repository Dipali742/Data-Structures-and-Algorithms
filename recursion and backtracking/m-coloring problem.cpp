 bool safeToColor(bool graph[101][101], int node, int c, vector<int>&color, int n) {
        for(int i = 0;i<n;i++) {
            if(graph[node][i] && color[i] == c)
                return false;
        }
        return true;
    }
    bool colored(bool graph[101][101], int m, int n, int node, vector<int>&color) {
        
        if(node == n)
            return true;
        
        for(int i=1;i<=m;i++) {
            if(safeToColor(graph, node, i, color, n)) {
                color[node] = i;
                if(colored(graph, m, n, node+1, color))
                    return true;
                color[node] = 0;
            }
        }
        
        return false;
    }
    
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>color(n, 0);
        return colored(graph, m, n, 0, color);
    }
