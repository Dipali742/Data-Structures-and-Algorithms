class Solution
{
public:

    string findString(int n, int k) {
        string ans = "";
        for(int i =0;i<n;i++) {
            ans+="0";
        }    
        k--;
        unordered_set<string>combinations;
        combinations.insert(ans);
        long long powerOfk = pow(k+1, n);
        while(combinations.size() < powerOfk) {
            string lastNMinusOnechars = ans.substr(ans.size()-(n-1));
            for(int i=k;i>=0;i--) {
                string current_string = lastNMinusOnechars;
                current_string += (i + '0');
                if(combinations.find(current_string) == combinations.end()) {
                    combinations.insert(current_string);
                    ans+=(i + '0');
                    break;
                }
            }
        }
        return ans;
    }
};
