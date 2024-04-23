/*
Given an array of positive integers (possibly with duplicates) such that the numbers have been sorted only by 28 most significant bits. Sort the array completely.

Example 1:

Input: [0, 15, 12, 17, 18, 19, 33, 32]
Output: [0, 12, 15, 17, 18, 19, 32, 33]
Explanation:
The integers in their binary representation are:
 0 = 0000 0000 0000 0000 0000 0000 0000 0000
15 = 0000 0000 0000 0000 0000 0000 0000 1111
12 = 0000 0000 0000 0000 0000 0000 0000 1100
17 = 0000 0000 0000 0000 0000 0000 0001 0001
18 = 0000 0000 0000 0000 0000 0000 0001 0010
19 = 0000 0000 0000 0000 0000 0000 0001 0011
33 = 0000 0000 0000 0000 0000 0000 0010 0001
32 = 0000 0000 0000 0000 0000 0000 0010 0000

In sorted order:
 0 = 0000 0000 0000 0000 0000 0000 0000 0000
12 = 0000 0000 0000 0000 0000 0000 0000 1100
15 = 0000 0000 0000 0000 0000 0000 0000 1111
17 = 0000 0000 0000 0000 0000 0000 0001 0001
18 = 0000 0000 0000 0000 0000 0000 0001 0010
19 = 0000 0000 0000 0000 0000 0000 0001 0011
32 = 0000 0000 0000 0000 0000 0000 0010 0000
33 = 0000 0000 0000 0000 0000 0000 0010 0001
*/


/*
  0 15 => one bucket
  16 to 31 => second bucket and so on...

  create 16 buckets inside first bucket and place elements
*/
class Solution {
public:
    vector<int> sortArray(vector<int>& A) {
        int i = 0;
        int n = A.size();
        while(i < n) {
           
            int start = i;
            int bucket[16];
            int bucketNum = A[i] & ~15;
            // cout<<"hello "<<A[i]<<" "<<endl;
            // Fill bucket
            while(i < n && (A[i] & ~15) == bucketNum) {
      
                int bucketPos = A[i] & 15;
                bucket[bucketPos]++;
                i++;
            }
         
            // Place sorted bucket
            for(int j = 0; j < 16; j++) {
                if(bucket[j] == 0) continue;
                while(bucket[j] > 0) {
                    A[start] = bucketNum + j;
                    start++;
                    bucket[j]--;
                }
            }
        }
        return A;
    }
};
