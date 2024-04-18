#include<bits/stdc++.h>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int arr[], int n)
{
    /*
        pick element and place at its correct position
        swap adjacent elements;
        time complexity = O(n^2);
    */

    for(int i = 0; i<n;i++) {
        int element = arr[i];
        int j = i;
        while( j>0 && arr[j] < arr[j-1]) {
            if(arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
            } else
                break;
            j--;
        }
    }
}
