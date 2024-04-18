int merge(vector<int>&arr, int low, int mid, int high)
    {
        vector<int>temp;
        int lefti = low;
        int righti = mid+1;
        int cnt = 0;
        while(lefti <= mid && righti <= high) {
            if(arr[lefti] <= arr[righti]) {
                temp.push_back(arr[lefti]);
                lefti++;
            } else {
                temp.push_back(arr[righti]);
                righti++;
                cnt += mid - lefti + 1;
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
        return cnt;
    }
    
    int mergeSort(vector<int>&arr, int l, int r)
    {
        if(l>=r)
            return 0;
        int cnt = 0;
        int mid = (l+r)/2;
        cnt += mergeSort(arr, l, mid);
        cnt +=  mergeSort(arr, mid+1, r);
        cnt +=  merge(arr, l, mid, r);
        return cnt;
    }
int numberOfInversions(vector<int>&a, int n) {
   return mergeSort(a, 0, n-1);
}
