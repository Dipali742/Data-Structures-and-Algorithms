/*
  Naive approach -> find all substrings and store in set 
  T(C) => O(n^3)
  S(C) => O(n^2)
  n is the length of the input string s
*/

int countDistinctSubstrings(string &s)
{
    unordered_set<string>st;
    for(int i=0;i<s.length();i++) {
        string str ="";
        for(int j=i;j<s.length();j++) {
            str+=s[j];
            st.insert(str);
        }

    }
    return st.size()+1;
}
