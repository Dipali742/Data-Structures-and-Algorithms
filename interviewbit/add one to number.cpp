vector<int> Solution::plusOne(vector<int> &A) {
    int n = A.size();
    int carry = 0;
    vector<int>ans;
    for(int i = n-1 ; i >= 0; i--) {
        if(i == n-1) {
            int number = A[i] + 1;
            carry = number/10;
            int digit = number%10;
            ans.push_back(digit);
        } else {
            int number = A[i] + carry;
            carry = number/10;
            int digit = number%10;
            ans.push_back(digit);
        }
    }
    if(carry != 0)
        ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i<ans.size();i++) {
        if(ans[i] == 0) {
            ans.erase(ans.begin());
            i--;
        }
        else
            break;
    }
    
    return ans;
}

/*

n-1 to 0
carry = 
1 2 9
    1
    
carry = 1 
2 + 1

    

*/
