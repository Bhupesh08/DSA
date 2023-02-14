class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1) {
            return nums[0];
        }
        
        int l=-1, r=n;
        
        while(r>l+1) {
            int mid = l - (l-r)/2;
            
            if(mid-1<0 && nums[mid] < nums[mid+1]) {
                return nums[mid];
            }
            
            if(mid+1==n && nums[mid] > nums[mid-1]) {
                return nums[mid];
            }
            
            if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) {
                return nums[mid];
            }
            
            else if(nums[mid]==nums[mid-1]) {
                if(mid % 2 == 1) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            
            else if(nums[mid]==nums[mid+1]) {
                if(mid % 2 == 0) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
        }
        
        return 0;
    }
};