void generate(vector<string>&ans, int n,int index, string current, int prev) {
    if(index == n) {
         ans.push_back(current);
         current.pop_back();
         return;
    }
      
    current += '0';
    generate(ans, n, index+1,current, 0);
    current.pop_back();

    if(!prev) {
        current+='1';
        generate(ans, n, index+1, current, 1);
        current.pop_back();
    }
}

vector<string> generateString(int N) {
    vector<string>ans;
    string current = "";
    generate(ans, N, 0, current, 0);
    return ans;
}
