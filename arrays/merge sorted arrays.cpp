class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m-1;
        int i2 = n-1;
        int ia = m+n-1;
        while(i1 >= 0 && i2 >= 0) {
            if(nums1[i1] > nums2[i2]) {
                nums1[ia] = nums1[i1];
                i1--;
                ia--;
            } else {
                nums1[ia] = nums2[i2];
                i2--;
                ia--;
            }
        }

        while(i1 >= 0) {
            nums1[ia] = nums1[i1];
            i1--;
            ia--;
        }
        while(i2 >= 0) {
            nums1[ia] = nums2[i2];
            i2--;
            ia--;
        }
    }
};
