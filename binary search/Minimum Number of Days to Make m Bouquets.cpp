class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = bloomDay.size();
        for(int i = 0 ; i<n;i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int mini_days = INT_MAX;
        int left = mini;
        int right = maxi;
        while(left <= right) {
            int mid = (left+right)/2;
            int bouquets = 0;
            int cnt =0;
            for(int j = 0; j<n;j++) {
                if(bloomDay[j] <= mid)
                    cnt++;
                else {
                    bouquets += cnt/k;
                    cnt = 0;
                }
            }
            if(cnt != 0) {
                bouquets += cnt/k;
            }

            if(bouquets >= m) {
                right = mid-1;
                mini_days = min(mini_days, mid);
            } else {
                left = mid + 1;
            }
        }
        return mini_days != INT_MAX ? mini_days : -1;
    }
};
