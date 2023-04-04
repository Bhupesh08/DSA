class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0, odd_count = 0, count = 0;
        
        while (right < nums.size()) {
            if(nums[right] % 2 == 1) {
                odd_count++;
            }
            
            // Check if the current sum is greater than the goal.
            while (left < right && odd_count > k) {
                // If it is, subtract the value at the left pointer from the sum
                // and move the left pointer to the right.
                if(nums[left] % 2 == 1) {
                    odd_count--;
                }
                left++;
            }
            
            // If the current sum equals the goal, increment the count of subarrays
            // and count the number of contiguous zeros on the left side of the subarray.
            if (odd_count == k) {
                count++;
                
                // Count the number of contiguous zeros on the left side of the subarray.
                int l = left;
                while (l < right && nums[l] % 2 == 0) {
                    count++;
                    l++;
                }
            }
            
            // Move the right pointer to the right.
            right++;
        }
        
        return count;
    }

    
};












// int numberOfSubarrays(vector<int>& nums, int k) {
//         int odd_count = 0;
//         int res = 0;
        
//         int i = 0, j = 0;
        
//         while(j < nums.size()) {
//             if(nums[j] % 2 == 1) {
//                 odd_count++;
//             }
            
//             while(odd_count > k) {
//                 if(nums[j] % 2 == 1) {
//                     odd_count--;
//                 }
//                 i++;
//             }
            
//             if(odd_count == k) {
//                 res++;
//             }
           
//             j++;
            
//         }
        
//         return res;
//     }