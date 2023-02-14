class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int res = INT_MAX;
        
        if(n==1) {
            return nums[0];
        }
        
        //Handling the edge case when the array is rotated n number of times and we got the original array back.
        if(nums[0] < nums.back()) {
            return nums[0];
        }
        
        int l = -1, r = n;
        
        while(r>l+1) {
            int mid = l - (l-r)/2;
            
            if(nums[mid] >= nums[0]) {
                l = mid;
            } else {
                res = min(res, nums[mid]);
                r = mid;
            }
            
            
        }
        
        
        return res;
        
    }
};