//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(vector<vector<int>> &m, int n, vector<string>&ans, string path, int row, int column) {
        
        if(row == n-1 && column == n-1) {
            ans.push_back(path);
            return;
        }
        
        if(row < 0 || row >=n || column >= n || column < 0 || m[row][column] == 0)
            return;
    
        int original = m[row][column];
        m[row][column] = 0;
        
        //up
        solve(m, n, ans, path +'U', row-1, column);
        
        //down
        solve(m, n, ans, path +'D', row+1, column);
        
        //left
        solve(m, n, ans, path +'L', row, column-1);
        
        //right
        solve(m, n, ans, path +'R', row, column+1);
        
        m[row][column] = original;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        if(m[n-1][n-1] == 0)
            return {};
        vector<string>ans;
        string path = "";
        solve(m, n, ans, path, 0, 0);
        return ans;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
