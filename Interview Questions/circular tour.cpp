class Solution{
  public:
  
    int tour(petrolPump p[],int n)
    {
        vector<int>petrols(n, 0);
        queue<pair<int, int>>que;
        int current = 0;
        int size_que = 0;
        int index = 0;
        
        for(int i=0;i<n;i++) {
            petrols[i] = p[i].petrol - p[i].distance;
        }
        
        while(size_que < n) {
            que.push({petrols[index], index});
            current = current + petrols[index];
            index = (index + 1) % n;
            size_que++;
           
            while(current < 0 && size_que > 0) {
                pair<int, int>pr = que.front();
                current -= pr.first;
                size_que--;
                que.pop();
                if(pr.second == n-1)
                    return -1;
            }
        }
        
        
        return que.front().second;
    }
};
