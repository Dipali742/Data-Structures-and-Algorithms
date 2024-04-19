/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval a, Interval b) {
    if(a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    if(A.size() == 0)
        return {};
    sort(A.begin(), A.end(), compare);
    int start_current = A[0].start;
    int end_current = A[0].end;
    vector<Interval>ans;
    
    for(int i = 1; i<A.size();i++) {
        if(A[i].start > end_current) {
            ans.push_back(Interval(start_current, end_current));
            start_current = A[i].start;
            end_current = A[i].end;
        } else if(A[i].end > end_current) {
            end_current = A[i].end;
        }
    }
    ans.push_back(Interval(start_current, end_current));
    return ans;
}
