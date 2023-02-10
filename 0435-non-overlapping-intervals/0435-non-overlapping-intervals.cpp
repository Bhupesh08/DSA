class Solution {
     private:
    
    static bool myComp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), myComp);
        
        vector<vector<int>> merged;
        int res = 0;
        int n = intervals.size();
        
        //traversing all the intervals
        for(int i=0; i<n; i++) {
            
            if(merged.empty()) {
                merged.push_back(intervals[i]);
            }
            
            else {
                vector<int> &previous = merged.back();
                
                int previous_end = previous[1];
                int current_start = intervals[i][0];
                
                if(current_start < previous_end) {
                    res++;
                    int current_end = intervals[i][1];
                    previous[1] = min(previous_end, current_end);
                } else {
                    merged.push_back(intervals[i]); 
                }
            }
        }
        return res;
    }
};