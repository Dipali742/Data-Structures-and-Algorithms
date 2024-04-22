class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        set<vector<int>>s;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++) {
            int a = arr[i];
            for(int j = i+1; j < n; j++) {
                int b = arr[j];
                int target = k - (a+b);
                int left = j+1;
                int right = n-1;
                while(left < right) {
                    if(arr[left] + arr[right] < target) {
                        left++;
                    } else if(arr[left] + arr[right] > target) {
                        right--;
                    } else {
                        s.insert({a, b, arr[left], arr[right]});
                        left++;
                        right--;
                    }
                }
            }
        }
        
        vector<vector<int>>ans;
        for(auto it: s) {
            ans.push_back(it);
        }
        return ans;
    }
};
