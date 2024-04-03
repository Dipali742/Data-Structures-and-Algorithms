/*
Sample Input 1 :
2
6
n ni nin ninj ninja ninga
2
ab bc
Sample Output 1 :
ninja
None
*/

/*
  Naive approach using map
  T(C) => O(n*[length of longest string in array])
  S(C) => O(n)
*/
string completeString(int n, vector<string> &a){
        unordered_map<string, int>mp;
        for(int i=0;i<n;i++) {
            mp[a[i]]++;
        }

        string ans = "";

        for(int i=0;i<n;i++) {
            string str = a[i];
            string prefix = "";
            string longestPrefix = "";
            for(int j=0;j<str.length();j++) {
                prefix+=str[j];
                if(mp.find(prefix) != mp.end())
                    longestPrefix = prefix;
                else {
                    longestPrefix = "";
                    break;
                }
            }
            if (ans.length() < longestPrefix.length()) {
                ans = longestPrefix;
            } else if (ans.length() == longestPrefix.length() && ans > longestPrefix)
                ans = longestPrefix;
        }

        return ans != "" ? ans : "None";
}
