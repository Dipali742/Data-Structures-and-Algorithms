class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        map<int, int>mp;
        for(int i = 0;i<n;i++) {
            mp[arr[i]]++;
        }
        int max_element = INT_MIN;
        int current_frequency = INT_MAX;
        for(auto it: mp) {
            if(it.second <= current_frequency && max_element < it.first) {
                max_element = it.first;
                current_frequency = it.second;
            }
        }
        
        
        return max_element;
    }
};
