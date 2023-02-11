class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int l=-1, r=nums.size();
        
        while(r>l+1) {
            int mid = l - (l-r)/2;
            
            if(nums[mid]>target) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        if(l==-1) return 0;
        else if(nums[l]!=target) return l+1;
        else return l;
        
    }
};