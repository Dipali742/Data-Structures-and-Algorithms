class Solution {
public:
    bool generateAllBinaryStrings(int n, int index, string &str, unordered_map<string, int>mp) {
        if(index == n) {
            if(mp.find(str) == mp.end()) {
                return true;
            }
            return false;
        }
        //recursive calls
        str+="0";
        if(generateAllBinaryStrings(n, index+1, str, mp))
            return true;
        str.pop_back();
        str+="1";
        if(generateAllBinaryStrings(n, index+1, str, mp))
            return true;
        str.pop_back();
        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        vector<string>binary_strings;
        int n = nums.size();
        unordered_map<string, int>mp;
        for(auto it: nums)
            mp[it]++;
        string ans = "";
        generateAllBinaryStrings(n,  0, ans,mp);
        return ans;
    }
};


class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;
        for (int i = 0; i < nums.size(); ++i) {
            result.push_back(nums[i][i] == '0' ? '1' : '0');
        }
        return result;
    }
};
