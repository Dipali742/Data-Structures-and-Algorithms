class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>mp;
        string initial_string = "0000";
        queue<pair<string, int>>que;
        que.push({initial_string, 0});
        for(int i =0; i<deadends.size();i++) {
            mp.insert(deadends[i]);
            if(deadends[i] == "0000")
                return -1;
        }
        mp.insert(initial_string);
        while(!que.empty()) {
            string current = que.front().first;
            string original = current;
            int steps = que.front().second;
            que.pop();
            
            if(current == target)
                return steps;

            for(int i =-4;i<=4;i++) {
                int index = (i+4)%5;
                if(i > 0) {
                    current[index] = (current[index] - '0' + 1)%10 + '0';
                } else if(i < 0) {
                    current[index] = (current[index] - '0' - 1 + 10)%10 + '0';
                }
                if(mp.find(current) == mp.end()) {
                    que.push({current, steps+1});
                    mp.insert(current);
                }
                current = original;
            }
        }
        return -1;
    }
};
