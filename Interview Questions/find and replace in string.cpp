class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        string ans = "";
        int str_index = 0;
        for(int i=0;i<Q;i++) {
            int curr_index = index[i];
            for(;str_index<curr_index&&str_index<S.length();str_index++) {
                ans+=S[str_index];
            }
            
            int temp_index = str_index;
            bool flg = true;
            for(;(temp_index-str_index)<sources[i].length()&&temp_index<S.length();temp_index++) {
                if(sources[i][temp_index-str_index] == S[temp_index]) {
                    continue;
                } else{
                    flg = false;
                    break;
                }
            }
            if(flg == true) {
                ans+=targets[i];
                str_index = temp_index;
            }
            
        }
        
        while(str_index < S.length()) {
            ans+=S[str_index];
            str_index++;
        }
        return ans;
    }
};
