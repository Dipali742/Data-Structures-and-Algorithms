class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        //take a brute force approach to make each pair one by one
        //keep pushing to a PQ - default max-heap but maintain a size of K on the queue

        int n1 = nums1.size();
        int n2 = nums2.size();

        priority_queue<pair<int,pair<int,int>>> pq;//default as max-heap
        //try to maintain a size of K

        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                int sum = nums1[i] + nums2[j];

                //we can handle break case for all consecutive sums, if sum exceeds beyond the top 3 values picked
                //as nums are in ascending
                if(pq.size() < k)
                {
                    pq.push({sum , {nums1[i], nums2[j]}});
                }
                else if(sum < pq.top().first)
                {
                    //pq is full, but we encountered a lower sum further
                    //adjust it into it
                    pq.pop();
                    pq.push({sum , {nums1[i], nums2[j]}});
                }
                else
                {
                    //pq is full, but we got a higher sum
                    //in this case current sum and all further sum are higher
                    break;
                }

            }
        }

        vector<vector<int>> res;

        while(!pq.empty())
        {
            int u = pq.top().second.first;
            int v = pq.top().second.second;

            pq.pop();

            res.push_back({u,v});
        }

        return res;
    }
};
