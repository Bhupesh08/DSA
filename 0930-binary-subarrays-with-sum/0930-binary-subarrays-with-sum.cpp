class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left = 0, right = 0, current_sum = 0, count = 0;
        
        while (right < nums.size()) {
            current_sum += nums[right];
            
            // Check if the current sum is greater than the goal.
            while (left < right && current_sum > goal) {
                // If it is, subtract the value at the left pointer from the sum
                // and move the left pointer to the right.
                current_sum -= nums[left];
                left++;
            }
            
            // If the current sum equals the goal, increment the count of subarrays
            // and count the number of contiguous zeros on the left side of the subarray.
            if (current_sum == goal) {
                count++;
                
                // Count the number of contiguous zeros on the left side of the subarray.
                int l = left;
                while (l < right && nums[l] == 0) {
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
