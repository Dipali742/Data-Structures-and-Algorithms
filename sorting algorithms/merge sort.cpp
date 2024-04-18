//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
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

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
