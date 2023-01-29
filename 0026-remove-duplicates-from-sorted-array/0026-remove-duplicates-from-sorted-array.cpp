class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int l = 1, r = 1;
        
        while(r!=n) {
            if(nums[r] != nums[r-1]) {
                nums[l] = nums[r];
                l++; r++;
            } else {
                r++;
            }
        }
        
        return l;
        
    }
};