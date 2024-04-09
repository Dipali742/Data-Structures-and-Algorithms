/*
  Naive = O(n^2) - trying out all possible combinations
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 0;
        for(int i=0;i<nums.size();i++) {
            int zeroes = 0;
            for(int j = i;j<nums.size();j++) {
                if(nums[j] == 0)
                    zeroes++;
                if(zeroes <= k)
                    max_len = max(max_len, j-i+1);
                else
                    break;
            }
        }
        return max_len;
    }
};

/*
 sliding window - O(2*N)
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 0;
        int l = 0;
        int r = 0;
				int zeroes = 0;
        while(r < n) {
						if(nums[r] == 0)
								zeroes++;
						while(zeroes > k) {
								if(nums[l] == 0)
									zeroes--;
								l++;
						}
						max_len = max(max_len, r - l + 1);
						r++;
				}
        return max_len;
    }
};

/*
 sliding window - O(N)
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int max_len = 0;
        int l = 0;
        int r = 0;
				int zeroes = 0;
        while(r < n) {
						if(nums[r] == 0)
								zeroes++;
						if(zeroes > k) {
								if(nums[l] == 0)
									zeroes--;
								l++;
						} else
						max_len = max(max_len, r - l + 1);
						r++;
				}
        return max_len;
    }
};
