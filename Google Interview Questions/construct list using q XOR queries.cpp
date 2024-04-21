class Solution {
  public:
    vector<int> constructList(vector<vector<int>> Q, int N) {
        map<int, int>mp;
        //index, xor
        vector<int>elements;
        elements.push_back(0);
        int index = 1;
        for(int i =0;i<N;i++) {
            if(Q[i][0] == 0) {
                elements.push_back(Q[i][1]);
                index++;
            } else {
                mp[index-1] = mp[index-1] ^ Q[i][1];
            }
        }
        
        int xorr = 0;
        for(int i = elements.size()-1;i>=0;i--) {
            if(mp.find(i) != mp.end()) {
                xorr = xorr^mp[i];
            }
            elements[i] = elements[i]^xorr;
        }
        sort(elements.begin(), elements.end());
        return elements;
    }
};



class Solution {
  public:
    vector<int> constructList(vector<vector<int>> Q, int N) {
        int xorr = 0;
        vector<int>elements;
        for(int i =N-1;i>=0;i--) {
            if(Q[i][0] == 0) {
                elements.push_back(xorr^Q[i][1]);
            } else {
                xorr = xorr ^ Q[i][1];
            }
        }
        
        elements.push_back(xorr);
        sort(elements.begin(), elements.end());
        return elements;
    }
};
