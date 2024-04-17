#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    int maxi = INT_MIN;
    for(int i = 0; i<n;i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
