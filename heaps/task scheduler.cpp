/*
  TLE - using PQ
  Time complexity = O(n * t * log 26) ≈ O(n*t)
*/  

class Solution {
public:
    int leastInterval(vector<char>& tasks, int t) {
        int n = tasks.size();
        vector<int>frequency(26, 0);
        for(auto ch : tasks) {
            frequency[ch-'A']++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>>pq;
        for(int i = 0; i< 26;i++) {
            if(frequency[i] >0 )
            {
               pq.push({frequency[i], i + 'A'});
            }
        }

        string ans = "";
        while(1) {
            for(int i = 0;i<=t;i++) {
                if(!pq.empty()) {
                    pair<int, char>task = pq.top();
                    ans+=task.second;
                    frequency[task.second - 'A']-=1;
                    pq.pop();
                } else 
                    ans+="_";
            }
            
            for(int i = 0;i<26;i++) {
                if(frequency[i] != 0)
                    pq.push({frequency[i], i + 'A'});
            }
            if(pq.size() == 0)
                break;
        }

        for(int i = ans.size()-1;i>=0;i--) {
            if(ans[i] == '_')
                ans.pop_back();
            else
                break;
        }
        return ans.size();
    }
};


/*
  Optimized using PQ
*/

  vector<int> frequency(26, 0);
    for (char ch : tasks) {
        frequency[ch - 'A']++;
    }

    priority_queue<int> pq;
    for (int freq : frequency) {
        if (freq > 0) {
            pq.push(freq);
        }
    }

    int time = 0;
    while (!pq.empty()) {
        int count = 0;
        vector<int> temp;
        while (count <= t && !pq.empty()) {
            int f = pq.top();
            pq.pop();
            if (--f > 0) {
                temp.push_back(f);
            }
            count++;
            time++;
        }
        for (int f : temp) {
            pq.push(f);
        }
        while (count <= t) {
            count++;
            if(!pq.empty())
                time++;
        }
    }
    return time;
