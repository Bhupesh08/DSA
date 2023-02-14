class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        bool res;
        
        int l=-1, r=n;
        
        while(r>l+1) {
            int mid = l - (l-r)/2;
            
            //if possible answer (mid) is our answer, return answer.
            if(nums[mid]==target) {
                return true;
            }
            
            //Handling duplicates:
            if(nums[mid]==nums[l+1] && nums[mid]==nums[r-1]) {
                l++;
                r--;
            }
            
            //is the left part sorted
            else if(nums[mid] >= nums[l+1]) {
                if(target>=nums[l+1] && target<nums[mid]) {
                    if(target==nums[l+1]) {
                        return true;
                    }
                    r = mid;
                } else {
                    l = mid;
                }
            }
            
            //if right part is sorted
            else {
                if(target>nums[mid] && target<=nums[r-1]) {
                    if(target==nums[r-1]) {
                        return true;
                    }
                    l = mid;
                } else {
                    r = mid;
                }
            }
            
            
        }
        
        return false;
        
    }
};