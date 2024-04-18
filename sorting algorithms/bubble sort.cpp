void bubbleSort(vector<int>& arr, int n) 
{
    /*
        adjacent swapping - move greater element at last
        time complexity = O(n^2)
        best case - o(n) - when array is already sorted, we can maintain one flg to check if adjacent pairs are getting swapped
    */
    bool flg = true;
    for(int i= n-1;i>=0;i--) {
        for(int j = 0; j<i;j++) {
            if(arr[j] > arr[j+1]) {
                flg = false;
                swap(arr[j], arr[j+1]);
            }          
        }
        if(flg)
            break;
    }
}
