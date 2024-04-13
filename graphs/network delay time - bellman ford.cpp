class Solution {
public:

    /*
      time complexity => O(V*E)
      space complexity => O(V)
    */
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1, INT_MAX); //O(V) space
        dist[k] = 0;
        for(int node = 0 ; node < n-1 ; node++) { //V times
            for(int edge = 0 ; edge < times.size() ; edge++) { //E times
                int src_node = times[edge][0];
                int dest_node = times[edge][1];
                int distance = times[edge][2];
                if(dist[src_node] != INT_MAX && dist[src_node] + distance < dist[dest_node])
                    dist[dest_node] = dist[src_node] + distance;
            }
        }

        int min_time = 0;
        for(int i = 1; i<=n; i++) { //V times
            if(dist[i] == INT_MAX)
                return -1;
            if(min_time < dist[i])
                min_time = dist[i];
        }
        return min_time;
    }
};
