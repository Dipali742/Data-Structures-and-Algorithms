 void find_lps(string pattern, vector<int>&lps, int pattern_len) {
    int l = 0;
    int r = 1;
    while(r < pattern_len) {
		if(pattern[l] == pattern[r]) {
			lps[r] = l + 1;
			l++;
			r++;
		} else if(l > 0) {
			l = lps[l-1];
		} else {
			r++;
		}
    }
 }

vector<int> stringMatch(string text, string pattern) {
	int n = pattern.length();
	int nt = text.length();
	vector<int>lps(n, 0);
	find_lps(pattern, lps, n);
	int it = 0;
	int ip = 0;
	vector<int>ans;
	while(it < nt) {
		if(text[it] == pattern[ip]) {
			it++;
			ip++;
		} else {
			if(ip > 0) {
				ip = lps[ip-1];
			} else {
				it++;
			}
		}
		if(ip == n) {
			ip = lps[ip-1];
			ans.push_back(it - n + 1);
		}
	}
	return ans;
}
