class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0;
        int totalSum = 0;
        for(int j=0; j<n; j++) {
            totalSum += nums[j];
        }
        
        if(totalSum - nums[0] == leftSum) {
            return 0;
        }
        
        for(int i=1; i<n; i++) {
            leftSum += nums[i-1];
            if(leftSum == totalSum - nums[i] - leftSum) {
                return i;
            }
        }
        
        return -1;
    }
        
        
};


