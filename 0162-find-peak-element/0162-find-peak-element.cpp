class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    
        int n = nums.size();
        
        int l=-1, r=n;
        
        //edge case - 1: when only 1 element is given, that given element will only be the peak element
        if(n==1) {
            return 0;
        }
        
        while(r>l+1) {
            int mid = l - (l-r)/2;
            
            //edge case - 2: when the first element is mid
            //therefore no need to check the left side, if that element is not mid, reduce the search space by bringing l to that element.
            if(mid==0) {
                if(nums[mid] > nums[mid+1]) {
                    return mid;
                } else {
                    l = mid;
                }
            } 
            
            //edge case - 3: when the last element is mid
            //therefore no need to check the right side, if that element is not mid, reduce the search space by bringing r to that element.
            else if(mid==n-1) {
                if(nums[mid] > nums[mid-1]) {
                    return mid;
                } else {
                    r = mid;
                }
            }
            
            else {
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                    return mid;
                } 
                
                else if(nums[mid] < nums[mid-1]) {
                    r = mid;
                } 
                
                else {
                    l = mid;
                }
            }
        }
        
        return 0;
    }
};


