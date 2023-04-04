class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0, odd_count = 0, count = 0;
        
        while (right < nums.size()) {
            if(nums[right] % 2 == 1) {
                odd_count++;
            }
            
            // Check if the no. of odd numbers in the subarray is greater than the required.
            while (left < right && odd_count > k) {
                // If it is, subtract the odd_count based on if left pointer is pointing to a odd/even number
                // and move the left pointer to the right.
                if(nums[left] % 2 == 1) {
                    odd_count--;
                }
                left++;
            }
            
            // If the no. of odd numbers in the subarray is equal to required, increment the count of subarrays
            // and count the number of contiguous even number on the left side of the subarray.
            if (odd_count == k) {
                count++;
                
                // Count the number of contiguous even number on the left side of the subarray.
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











