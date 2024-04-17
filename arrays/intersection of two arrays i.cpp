class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0;
        int i2 = 0;
        int ians = -1;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>ans;
        while(i1 < nums1.size() && i2 < nums2.size()) {
            if(nums1[i1] == nums2[i2]) {
                if(ians == -1 || ans[ians] != nums1[i1]) {
                    ans.push_back(nums1[i1]);
                    ians++;
                }
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

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> map;
        vector<int> result;
        for (auto it : nums1) {
            map[it] = 1;
        }
        for (auto it : nums2) {
            if (map[it] == 1) {
                result.push_back(it);
                map[it] = 0;
            }
        }
        return result;
    }
};
