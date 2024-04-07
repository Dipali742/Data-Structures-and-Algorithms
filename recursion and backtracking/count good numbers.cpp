#define mod 1000000007

class Solution {
public:
    long long myPow(long long x, int n) {
        if(n==0) return 1;
      
        if(n%2==0){
            return myPow((x*x)%mod, n/2)%mod;
        }
        else{
            return (x*myPow(x, n-1))%mod;
        }
    }

    int countGoodNumbers(long long n) {
        long long numberOfOddPlaces = n/2;
        long long numberOfEvenPlaces = (n+1)/2;
        return (myPow(5, numberOfEvenPlaces) * myPow(4, numberOfOddPlaces))%mod;
    }
};
