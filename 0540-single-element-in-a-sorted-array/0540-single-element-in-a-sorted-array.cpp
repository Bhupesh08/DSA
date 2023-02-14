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
            
            //edge case when mid is pointing to the 0th index
            if(mid-1<0 && nums[mid] < nums[mid+1]) {
                return nums[mid];
            }
            
            //edge case when mid is pointing to the (n-1)th index
            if(mid+1==n && nums[mid] > nums[mid-1]) {
                return nums[mid];
            }
            
            //Main condition which is to be satisfied for mid to be our actual answer
            if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) {
                return nums[mid];
            }
            
            //Case A: When element (where mid is pointing) is the second occurrence of that element
            else if(nums[mid]==nums[mid-1]) {
                //if second occurrence present at odd index: Distortion abhi tak hua nahi hai and
                //the desired element is on the right side
                if(mid % 2 == 1) {
                    l = mid;
                //else desired element is on the left side
                } else {
                    r = mid;
                }
            }
            
            //Case B: When element (where mid is pointing) is the first occurrence of that element
            else if(nums[mid]==nums[mid+1]) {
                //if first occurrence present at even index: Distortion abhi tak hua nahi hai and
                //the desired element is on the right side
                if(mid % 2 == 0) {
                    l = mid;
                //else desired element is on the left side
                } else {
                    r = mid;
                }
            }
        }
        
        return 0;
    }
};