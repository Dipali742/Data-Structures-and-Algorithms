void selectionSort(vector<int>&arr) {
    /*
        find smaller element and place it at the start 
        time complexity = O(n^2)
    */

    for(int i = 0;i<arr.size();i++) {
        int mini = INT_MAX;
        int mini_index = i;
        for(int j = i;j<arr.size();j++) {
            if(arr[j] < mini) {
                mini = arr[j];
                mini_index = j;
            }
           
        }
        swap(arr[i], arr[mini_index]);
    }
}
