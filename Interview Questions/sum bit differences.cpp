class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    
	    long long cnt = 0;
	    for(int i = 0;i<32;i++) {
	        int set_bits = 0;
	        for(int j =0;j<n;j++) {
	            if(arr[j] & (1<<i))
	                set_bits++;
	        }
	        cnt+=(long long)set_bits*(long long)(n-set_bits)*2LL;
	    }
	    return cnt;
	}
};
