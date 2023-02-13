//Method-2: By Striver and alisha didi: More intuitive and easier code

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
            
            //is the left part sorted
            else if(nums[mid] >= nums[l+1]) {
                if(target>=nums[l+1] && target<nums[mid]) {
                    if(target==nums[l+1]) {
                        return l+1;
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
                        return r-1;
                    }
                    l = mid;
                } else {
                    r = mid;
                }
            }
            
            
        }
        
        return -1;
        
    }
};
