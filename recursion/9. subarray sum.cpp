/*
  time complexity - O(n^2)
  space complexity - O(n) - recursion stack space
*/


#include<bits/stdc++.h>

void generate(vector<vector<int>>&ans,vector<int>&row,vector<int>&nums, int k, int index) {
   
    if(index == nums.size()) {
       return;
    }
    
    row.push_back(nums[index]);
    int sum = 0;
    for(int i = row.size()-1;i>=0;--i) {

        sum+=row[i];
        if(sum == k) {
            ans.push_back(vector<int>(row.begin() + i, row.end()));
        }
    }
    generate(ans, row, nums, k, index + 1);
    row.pop_back();
}

vector<vector<int>> subarraysWithSumK(vector<int> a, int k) {
    vector<vector<int>>ans;
    vector<int>row;
    generate(ans, row, a, k, 0);
    return ans;
}


/*
  sliding window 
  time complexity - O(n)
  space complexity - O(1)
*/

vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    int start = 0;
    int end = -1;
    vector<vector<int>>ans;
    long long currentSum = 0;
    int n = a.size();
    while(start < n) {
        while((end + 1) < n && (currentSum + a[end+1]) <= k) {
            currentSum += a[end+1];
            end++;
        }

        if(currentSum == k) {
            ans.push_back(vector<int>(a.begin() + start, a.begin() + end + 1));
        }

        currentSum -= a[start];
        start++;
    }
    return ans;
}
