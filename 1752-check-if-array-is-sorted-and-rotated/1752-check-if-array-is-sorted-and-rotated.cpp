
//to solve this question u just need to make one observation. 
//Observation: As we go from LHS to the RHS in the given array, the value of nums[i] will always be less than that of nums[i+1] (use nums[(i+1)%n] because concept of rotation is involved) 
//except for one case like jispe rotation hua ho.

class Solution {
public:
    bool check(vector<int>& nums) {

        int count = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            if(nums[i]>nums[(i+1)%n]) count++;
        }

        return count<=1;
        
    }
};
