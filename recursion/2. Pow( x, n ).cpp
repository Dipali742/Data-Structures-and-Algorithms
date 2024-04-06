class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return  (double)1;
        
        if(n < 0)
            return  (double)myPow(x, n+1)/x;
        else
            return  (double) x*myPow(x, n-1);
    }
};
