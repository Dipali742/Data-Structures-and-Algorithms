/*

baa
abcd

b>a => b->a

abcd abca
d>a => 

*/

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>>adjList(K);
        vector<int>inorder(K, 0);
        for(int i = 1; i<N;i++) {
            string current = dict[i];
            string previous = dict[i-1];
            for(int j = 0;j<previous.length();j++) {
                if(previous[j] != current[j]) {
                    adjList[previous[j]-'a'].push_back(current[j]-'a');
                    inorder[current[j]-'a']++;
                    break;
                } 
            }
        }
        
        queue<int>que;
        for(int i = 0; i<K;i++) {
            if(inorder[i] == 0)
                que.push(i);
        }
        
        vector<char>ans;
        while(!que.empty()) {
            int current = que.front();
            que.pop();
            ans.push_back(current+'a');
            for(auto i: adjList[current]) {
                inorder[i]--;
                if(inorder[i] == 0) {
                    que.push(i);
                }
            }
        }
        
        string res = "";
        for(int i = 0;i<ans.size();i++) {
            res+=ans[i];
        }
        // cout<<res<<endl;
        return res;
    }
};
