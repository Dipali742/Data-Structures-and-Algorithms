class Solution {
  public:
    vector<int> printMissingIntervals(int arr[], int n) {
        vector<int>ans;
        int start = 0;
        for(int i = 0; i<n;i++) {
            if(arr[i] != start) {
                ans.push_back(start);
                ans.push_back(arr[i]-1);
            } 
            start = arr[i]+1;
        }
        if(arr[n-1] != 99999) {
            ans.push_back(arr[n-1]+1);
            ans.push_back(99999);
        }
        return ans;
    }
};
