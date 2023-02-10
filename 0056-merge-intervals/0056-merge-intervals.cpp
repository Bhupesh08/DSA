class Solution {
    private:
    
    static bool myComp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    }

    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        //simply sorting would have worked as well
        sort(intervals.begin(), intervals.end(), myComp);
        
        vector<vector<int>> merged;
        
        int n = intervals.size();
        
        //traversing all the intervals
        for(int i=0; i<n; i++) {
            
            if(merged.empty()) {
                merged.push_back(intervals[i]);
            }
            
            else {
                //Declaring by reference because we want to update the value in the original vector itself.
                vector<int> &previous = merged.back();
                
                int previous_end = previous[1];
                int current_start = intervals[i][0];
                
                if(current_start <= previous_end) {
                    //the intervals overlap
                    //No need to push anything, just update the previously pushed intervals' end value
                    int current_end = intervals[i][1];
                    //max of the both because consider cases like [0,3] & [0,8] -----> [0,8]
                    // if [0,7] & [1,4] -----> [0,7]
                    previous[1] = max(previous_end, current_end);
                } else {
                    //the intervals do not overlap
                    //just push the current interval into the merged one
                    
                    merged.push_back(intervals[i]);
                    
                }
            }
        }
              
        
    return merged;
        
    }
};




