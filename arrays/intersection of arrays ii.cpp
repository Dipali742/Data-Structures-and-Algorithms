class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0;
        int i2 = 0;
        int ians = -1;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>ans;
        while(i1 < nums1.size() && i2 < nums2.size()) {
            if(nums1[i1] == nums2[i2]) {
                ans.push_back(nums1[i1]);
                ians++;
                i1++;
                i2++;
            } else if(nums1[i1] > nums2[i2]) {
                i2++;
            } else {
                i1++;
            }
        }
        return ans;
    }
};
