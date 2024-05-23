class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<int>indices;
        vector<long long>ans(n, -1);
        for(int i = 0; i < n; i++) {
            if(indices.empty()) {
                indices.push(i);
                continue;
            }
            while(!indices.empty() && arr[indices.top()] < arr[i]) {
                ans[indices.top()] = arr[i];
                indices.pop();
            }
            indices.push(i);
        }
        return ans;
    }
};
