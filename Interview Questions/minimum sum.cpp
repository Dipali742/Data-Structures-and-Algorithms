class Solution{   
public:
    string solve(int arr[], int n) {
       sort(arr, arr+n);
       string sum1 = "";
        string sum2 = "";
       for(int i = 0 ; i< n;i++) {
           if(i%2 == 0)
            sum1+=(arr[i]+'0');
         else
            sum2 += (arr[i]+'0');
       }
       
       int carry = 0 ;
       if(sum1.length() > sum2.length()) {
           swap(sum1, sum2);
       }
       int len = sum2.length();
       int j = sum1.length()-1;
       for(int i = len - 1; i >= 0; i--) {
           int a = 0;
           if(j >= 0) {
               a = sum1[j] - '0';
               j--;
           }
           int b = sum2[i] - '0';
           int digit = (carry + a + b)%10;
           carry = (carry + a + b)/10;
           sum2[i] = digit + '0';
       }
       
       if(carry != 0) {
           char ch = carry + '0';
           string new_ans = "";
           new_ans += ch;
           new_ans += sum2;
           return new_ans;
       }
       string ans = "";
       int i = 0;
       for(; i<len;i++) {
           if(sum2[i] != '0')
                break;
       }
       
       if(i == len)
        return "0";
       return sum2.substr(i, len);
    }
};
