class Solution {
    
private:
    bool good(vector<int>& nums, int threshold, int divisor) {
        
        int n = nums.size();
        double sum = 0;
        
        for(int i=0; i<n; i++) {
            sum += ceil((double)nums[i]/(double)divisor);
        }
        
        if(sum <= threshold) {
            return true;
        } 
        
        return false;
    }
    
    
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        
        //edge case:
        if(n==1) {
            return ceil((double)nums[0]/(double)threshold);
        }
        
        int maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
            }
        }
        
        int l = 0;
        int r = maxi + 1;
        
        while(r > l+1) {
            int mid = l - (l-r)/2;
            
            if(good(nums, threshold, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return r;
       
    }
};