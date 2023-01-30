class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
         //Time complexity = O(n) and Space complexity = O(n)

        int n = nums.size();
//         vector<int> arr(n, 0);

//         for(int i = 0; i < n; i++) {

//             arr[(i+k)%n] = nums[i];

//         }


//         nums = arr;
        
        //Time complexity = O(n) and Space complexity = O(1)
        
        k = k % n;

        reverse(nums.begin(), nums.end());
        
        reverse(nums.begin(), nums.begin() + k);
        
        reverse(nums.begin() + k, nums.end());
        
        
        
        
        
        
    }
};