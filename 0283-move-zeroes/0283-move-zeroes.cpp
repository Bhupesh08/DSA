class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int l = 0; 
        int n = nums.size();
        
        //look how putting l < n after the first condition results in run time error
        while( l < n && nums[l] != 0) {
            l++;
        }
        
        //The code below this can be replaced by the commented code
        int r = l + 1;

        while(r<n) {
            if(nums[r] != 0) {
                swap(nums[r], nums[l]);
                r++;
                l++;
            } else r++;
        }

        
        // for(int r= l+1; r<n; r++) {
        //     if(nums[r] != 0) {
        //         swap(nums[r], nums[l]);
        //         l++;
        //     }
        // }
}

};
