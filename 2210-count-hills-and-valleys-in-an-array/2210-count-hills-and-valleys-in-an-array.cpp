class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int n = nums.size();
        
        int res = 0;
        
        //the main difficulty of the problem is in handling the duplicates
        //we will handle the duplicates using the second pointer j
        //First pointer i will be pointing to the index in question.
        //peeche wali condition will be checked using j and agge wali condition using i+1
        //we will increment j only when a hill or valley is encountered, in this way we will make sure that j is pointing to non equal element only
        
        int j = 0;
        
        for(int i=1; i<n-1; i++) {
            //if(HILL || VALLEY):
            if((nums[j] < nums[i] && nums[i] > nums[i+1]) || (nums[j] > nums[i] && nums[i] < nums[i+1])) {
                res++;
                j = i;
            }
        }
        
        
        return res;
    }
};