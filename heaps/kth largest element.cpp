/*
  sort
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0;i<nums.size();i++)
            cout<<nums[i]<<" ";
        return nums[k - 1];
    }
};

/*
  max heap
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>>pq;
        for(int i = 0;i<nums.size();i++) {
            pq.push(nums[i]);
        }

        while(k > 0) {
            int top = pq.top();
            k--;
            if(k == 0)
                return top;
            pq.pop();
        }
        return -1;
    }
};
/*
  Quickselect
*/
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left] ;
    int l = left + 1 ;
    int r = right;
    while (l <= r) {
        if (arr[l] < pivot && arr[r] > pivot) {
            swap(arr[l], arr[r]);
            l++ ;
            r-- ;
        }
        if (arr[l] >= pivot) {
            l++;
        }
        if (arr[r] <= pivot) {
            r--;
        }
    }
    swap(arr[left], arr[r]);
    return r;
}

int kth_Largest_Element(vector<int>& arr, int k) {
    int left = 0, right = arr.size() - 1, kth;
    while (1) {
        int idx = partition(arr, left, right);
        if (idx == k - 1) {
            kth = arr[idx];
            break;
        }
        if (idx < k - 1) {
            left = idx + 1;
        } else {
            right = idx - 1;
        }
    }
    return kth;
}
