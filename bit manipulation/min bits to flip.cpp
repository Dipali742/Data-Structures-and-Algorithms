class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr = start ^ goal;
        int cnt = 0;
        for(int i = 0 ; i<32;i++) {
            if(xorr >> i & 1)
                cnt++;
        }
        return cnt;
    }
};
