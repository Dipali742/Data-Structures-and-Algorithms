class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        vector<int>leftMin(n, 0);
        vector<int>rightMax(n, 0);
        leftMin[0] =  0;
        for(int i=1;i<n;i++) {
            if(arr[leftMin[i-1]] <= arr[i])
                leftMin[i] = leftMin[i-1];
            else
                leftMin[i] = i;
        }
        rightMax[n-1] = n-1;
        for(int i = n-2;i>=0;i--) {
            if(arr[rightMax[i+1]] >= arr[i])
                rightMax[i] = rightMax[i+1];
            else
                rightMax[i] = i;
        }
        
        int left = 0;
        int right = 0;
        int max_diff = 0;
        int max_diff_index = 0;
        while(left <n && right < n) {
            if(arr[leftMin[left]] <= arr[rightMax[right]]) {
                int diff = rightMax[right] - leftMin[left];
                if(diff > max_diff_index) {
                    max_diff = diff;
                    max_diff_index = rightMax[right]-leftMin[left];
                }
                right++;
            }
            else {
                left++;
            }
        }
        
        return max_diff_index;
    }

};
