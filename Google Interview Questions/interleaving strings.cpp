class Solution{
  public:
    bool recursive(string A, string B, string C, int ai, int bi, int ci, vector<vector<int>>&dp) {
        if(ci == C.length())
            return true;
        if(ai == A.length() && bi == B.length())
            return false;
        
        if(dp[ai][bi] != -1)
            return dp[ai][bi];
        //all equal
        bool all_equal = false;
        bool a_equal = false;
        bool b_equal = false;
        if(ai < A.length() && bi < B.length() && A[ai] == B[bi] && C[ci] == A[ai]) {
            all_equal = (recursive(A, B, C, ai+1, bi, ci+1, dp) || recursive(A, B, C, ai, bi+1, ci+1, dp));
        } else if(ai < A.length() && A[ai] == C[ci]) {
            a_equal = recursive(A, B, C, ai+1, bi, ci+1, dp);
        } else if(bi < B.length() && B[bi] == C[ci]) {
            b_equal = recursive(A, B, C, ai, bi+1, ci+1, dp);
        } 
        
        return dp[ai][bi] = all_equal || a_equal || b_equal;
    }
    
    bool isInterleave(string A, string B, string C) 
    {
        if(A.length() + B.length() != C.length())
            return false;
        vector<vector<int>>dp(A.length()+1, vector<int>(B.length()+1, -1));
        return recursive(A, B, C, 0, 0 , 0, dp);
    }

};
