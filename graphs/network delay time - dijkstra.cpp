class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adjList(n+1);
        for(int i = 0; i<times.size(); i++) {
            adjList[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        /*
            time complexity is O((V + E) * log V) and the space complexity is O(V + E).
            adjList 
            0
            1 => 
            2 => {1, 1}, {3, 1}
            3 => {4, 1}
            4 =>

            dist[] =>
            pq =>
            {0, 2}
        */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, k});
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        while(!pq.empty()) {
            pair<int, int>front = pq.top();
            pq.pop();
            int current_distance = front.first;
            int current_node = front.second;
            for(int i = 0; i < adjList[current_node].size(); i++) {
                //relax the edge
                int next_node = adjList[current_node][i].first;
                int next_distance = adjList[current_node][i].second;
                if(next_distance + current_distance < dist[next_node]) {
                    dist[next_node] = next_distance + current_distance;
                    pq.push({dist[next_node], next_node});
                }
            }
        }

        int min_time = 0;
        for(int i = 1; i<=n; i++) {
            if(dist[i] == INT_MAX)
                return -1;
            if(min_time < dist[i])
                min_time = dist[i];
        }
        return min_time;
    }
};
