/*
time complexity: O(2^n)
space complexity: O(n) - recursion stack space
*/

void generate(vector<string>&ans, int n,int index, string current, int prev) {
    if(index == n) {
         ans.push_back(current);
         return;
    }
      
    generate(ans, n, index+1,current+'0', 0);

    if(!prev) {
        generate(ans, n, index+1, current+'1', 1);
    }
}

vector<string> generateString(int N) {
    vector<string>ans;
    generate(ans, N, 0, "", 0);
    return ans;
}
