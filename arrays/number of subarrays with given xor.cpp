int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int>preXor;
    int pre_xor = 0;
    int cnt =0;
    for(int i = 0; i<A.size();i++) {
        pre_xor = pre_xor^A[i];
        cnt+=preXor[pre_xor^B];
     
        if(pre_xor == B)
            cnt++;
        
        preXor[pre_xor]++;
    }
    return cnt;
}
