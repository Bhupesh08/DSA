class Solution {
public:
    //This question is not an obvious sliding window question, but one observation changes everything.
    //In this question, we are basically looking for a window to eliminate
    int maxScore(vector<int>& cardPoints, int k) {
        int window_size = cardPoints.size() - k;
        int total_sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int i = 0, j = 0;
        int res = INT_MIN;
        int window_sum = 0;
        
        //The only base case:
        if(window_size == 0) return total_sum;
        
        //sliding window chalu
        while(j < cardPoints.size()) {
            //Calculation
            window_sum += cardPoints[j];
            
            //move j forward till window size is not acheived
            if(j-i+1 < window_size) j++;
            
            //window_size achieved, now keep it constant
            else if(j-i+1 == window_size) {
                //the main crux of the solution lies here
                res = max(res, total_sum - window_sum);
                
                //Undo the calculation
                window_sum -= cardPoints[i];
                
                //sliding the window
                i++;
                j++;
            }
        }
        
        return res;
    }
};