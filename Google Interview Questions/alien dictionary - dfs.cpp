class Solution{

    public:
    
    void dfs(vector<vector<int>>&adjList, int K, int node, stack<int>&stk, vector<int>&visited) {
        
        visited[node] = 1;
        for(auto it : adjList[node]) {
            if(!visited[it]) {
                dfs(adjList, K, it, stk, visited);
            }
        }
        stk.push(node);
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>>adjList(K);
        for(int i = 1; i<N;i++) {
            string current = dict[i];
            string previous = dict[i-1];
            for(int j = 0;j<previous.length();j++) {
                if(previous[j] != current[j]) {
                    adjList[previous[j]-'a'].push_back(current[j]-'a');
                    break;
                } 
            }
        }
        vector<int>visited(K, 0);
        stack<int>topo;
        string res = "";
        for(int i = 0 ;i < K;i++) {
            if(!visited[i])
                dfs(adjList, K, i, topo, visited);
        }
            
        while(!topo.empty()) {
            res+=(topo.top() + 'a');
            topo.pop();
        }
        return res;
    }
};
