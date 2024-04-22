class Solution 
{
    public:
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int>inDegree(n, 0);
        vector<int>outDegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n ; j++) {
                if(M[i][j] == 1) {
                    inDegree[j]++;
                    outDegree[i]++;
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            if(inDegree[i] == n-1 && outDegree[i] == 0)
                return i;
        }
        
        return -1;
    }
};
