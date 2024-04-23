class Solution {
public:
    int leastInterval(vector<char>& tasks, int t) {
        int n = tasks.size();
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
    }
};
