class Solution 
{
    
    /*
        0 1 2
        2 1
        
        0 1
        
        1 0
        1
    */
    
    public:
    
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        stack<int>stk;
        for(int i = 0 ; i < n ; i++) {
            stk.push(i);
        }
        
        while(stk.size() > 1) {
            int first = stk.top();
            stk.pop();
            int second = stk.top();
            stk.pop();
            
            //first knows second - first can't be celebrity
            if(arr[first][second]) {
                stk.push(second);
            } else {
                stk.push(first);
            }
        }
        
        int celebrity = stk.top();
        
        for(int i = 0; i<n;i++) {
            if(arr[celebrity][i] == 1)
                return -1;
        }
        
        for(int i = 0; i<n;i++) {
            if(i != celebrity && arr[i][celebrity] == 0)
                return -1;
        }
        return stk.top();
    }
};
