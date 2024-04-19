class Solution
{
    private:
    priority_queue<int>max_heap;
    priority_queue<int, vector<int>, greater<int>>min_heap;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(!max_heap.empty()) {
            if(max_heap.top() >= x)
                max_heap.push(x);
            else
                min_heap.push(x);
        } else {
            max_heap.push(x);
        }
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int max_heap_size = max_heap.size();
        int min_heap_size = min_heap.size();
        if(max_heap_size - min_heap_size > 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if(max_heap_size - min_heap_size < -1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        int max_heap_size = max_heap.size();
        int min_heap_size = min_heap.size();
        if(max_heap_size > min_heap_size)
            return max_heap.top();
        else if(max_heap_size < min_heap_size)
            return min_heap.top();
        else
            return (double)(max_heap.top() + min_heap.top())/2;
    }
};
