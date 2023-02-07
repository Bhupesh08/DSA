class Solution {
public:
    void sortColors(vector<int>& nums) {

//         //Method - 1 : Using bucket/bin sort
//         //Intuition: as input is drawn from a fixed set i.e. {0, 1, 2}. 
//         //Bucket sort is a generalization of counting sort.
        
//         vector<int> bin(3, 0);
        
//         int n = nums.size();
        
//         //creating the bucket
//         for(int i=0; i<n; i++) {
//             bin[nums[i]]++;
//         }
        
//         //Sorting the given array in-place using the created bucket.
//         int i = 0, j = 0;
        
//         while(i<3) {
//             while(bin[i]) {
//                 nums[j++] = i;
//                 bin[i]--;
//             }
//             i++;
//         }
        
        //Method-2 : Using partition technique
        //Better solution than previous method because we achieve the result in one pass only.
        int n = nums.size();
        
        int low = 0;
        int mid = 0;
        int high =n-1;
        
        while(mid<=high) {
            
            if(nums[mid]==0) {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            
            else if(nums[mid]==1) {
                mid++;
            }
            
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
                
        }
        
        
    }
};