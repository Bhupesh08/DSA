class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int l=-1, r=n;
        
        while(r>l+1) {
            int mid = l - (l-r)/2;
            
            //if possible answer (mid) is our answer, return answer.
            if(nums[mid]==target) {
                return mid;
            }
            
            //case when mid lies in the Left sorted array
            //l+1 because it takes care of the edge case when l = -1.
            else if(nums[mid] >= nums[l+1]) {
                if(target > nums[mid]) {
                    l = mid;   //No confusion: target lies in Right search space
                }
                 
                else if(target < nums[mid]) {   //confusion as target could be present in either of the search space
                    if(target > nums[l+1]) {
                        r = mid;
                    } 
                
                    else if(target < nums[l+1]) {
                        l = mid;
                    } 
                    //this else becomes important as equality condition pe r = mid ho rha tha and l+1 wale ke chance the ki wo search space se bahar chala jaata which we dont want as it could be our potential answer.
                    else {
                        return l+1;
                    }
                }
            }
            
            //mid lies in the right sorted array
            else {
                if(target < nums[mid]) {
                    r = mid;
                }
                
                else if(target > nums[mid]) {
                    if(target > nums[r-1]) {
                        r = mid;
                    } 
                    
                    else if(target < nums[r-1]) {
                        l = mid;
                    } 
                    
                    else {
                        return r-1;
                    }
                }
            }
        }
        
        return -1;
        
    }
};