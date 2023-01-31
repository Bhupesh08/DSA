class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        //the below solution looks nice but there was no need to check that in if statment.
        //we can simply run a for loop and increment count as 1 is encountered.
        
//         int mxOne = 0;
//         int count = 1;
//         int l = 1;
        
//        if((nums[0]==0 && nums.size()==1) || (nums[0]==0 && nums[1]==0 && nums.size()==2)) {
//            return 0;
//        }
       

//         while(l < nums.size()) {
//             if(nums[l] && nums[l-1]) {
//                 count++;
//                 l++;
//                 mxOne = max(mxOne, count);
//             } else {
//                 count = 1;
//                 l++;
//             }
            
           
//         }
        
        
//         return max(mxOne, count);
        
        //much more simple and better code
        int count = 0;
        int maxi = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==1) {
                count++;
            }else {
                count = 0;
            }
            
            maxi = max(maxi, count);
        }
        
        return maxi;
        
        
    }
};