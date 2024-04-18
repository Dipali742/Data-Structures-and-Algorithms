class Solution {
public:

    void merge(vector<int>& arr, int low, int mid, int high)
    {
        vector<int>temp;
        int lefti = low;
        int righti = mid+1;
        while(lefti <= mid && righti <= high) {
            if(arr[lefti] <= arr[righti]) {
                temp.push_back(arr[lefti]);
                lefti++;
            } else {
                temp.push_back(arr[righti]);
                righti++;
            }
        }
        
        while(lefti <= mid) {
            temp.push_back(arr[lefti]);
            lefti++; 
        }
        
        while(righti <= high) {
            temp.push_back(arr[righti]);
            righti++; 
        }
        
        for(int i = 0;i<temp.size();i++) {
            arr[low+i] = temp[i];
            // low++;
        }
    }
    
    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2 * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& arr, int l, int r)
    {
        if(l>=r)
            return 0;
        int mid = (l+r)/2;
        int cnt = 0;
        cnt += mergeSort(arr, l, mid);
        cnt += mergeSort(arr, mid+1, r);
        cnt += countPairs(arr, l, mid, r);
        merge(arr, l, mid, r);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
