int Solution::repeatedNumber(const vector<int> &A) {
    if(A.size() <= 1)
        return A[0];
    int cnt1 = 0;
    int element1 = 0;
    int cnt2 = 0;
    int element2 = 0;
    for(int i =0;i<A.size();i++) {
        if(cnt1 == 0 && element2 != A[i]) {
            cnt1 =1;
            element1 = A[i];
        } else if(cnt2 == 0 && element1 != A[i]) {
            cnt2 = 1;
            element2 = A[i];
        } else if(A[i] == element1) {
            cnt1++;
        } else if(A[i] == element2) {
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        } 
    }
    
    cnt1 = 0;
    cnt2 = 0;
    int n = A.size();
    for(int i =0;i<n;i++) {
        if(A[i] == element1)
            cnt1++;
        if(A[i] == element2)
            cnt2++;
        
    }
    
    if(cnt1 > n/3)
    return element1;
    if(cnt2 > n/3)
        return element2;
    return -1;
}
