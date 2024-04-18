class Solution
{
    public:
    void merge(int arr[], int low, int mid, int high)
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
        
        while(righti <= mid) {
            temp.push_back(arr[righti]);
            righti++; 
        }
        
        for(int i = 0;i<temp.size();i++) {
            arr[low] = temp[i];
            low++;
        }
    }
    
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r)
            return;
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};
