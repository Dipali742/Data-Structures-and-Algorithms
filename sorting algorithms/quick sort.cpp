class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low >= high)
            return;
        
        int pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index-1);
        quickSort(arr, pivot_index+1, high);
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       int i = low;
       int j = high;
       int pivot_index = low;
       
       while(i < j) {
           
           while(i <= high-1 && arr[i] <= arr[pivot_index]) {
               i++;
           }
           
           while(j >= low+1 && arr[j] > arr[pivot_index]) {
               j--;
           }
           
           if(i < j)
                swap(arr[i], arr[j]);
            else
            break;
       }
       
       swap(arr[pivot_index], arr[j]);
       
       return j;
    }
};
