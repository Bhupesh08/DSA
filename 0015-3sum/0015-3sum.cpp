class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /* using the two pointer approach */
        
        int n = nums.size();
        sort(nums.begin(), nums.end()); //array should be sorted to use two pointer
        
        vector<vector<int>> ans;
        
        for(int i=0; i<n-2; i++) {
            //this if statement makes sure that we dont iterate again for same value of i for
            //which previous iteration was done
            if(i==0 || (i>0 && nums[i] != nums[i-1])) {
                
                int j = i+1;
                int k = n-1;
            
                while(j<k) {

                    if(nums[j] + nums[k] == -nums[i]) {

                    vector<int> v;
                    v.push_back(nums[i]);                   
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    ans.push_back(v);
                    
                    //the below while statement makes sure that the vector doesnt contain
                    //duplicate triplets.
                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;

                    j++;
                    k--;
                    }
                
                    else if(nums[j] + nums[k] < -nums[i]) {
                    j++;
                    
                    }else {
                    k--;
                    
                    }
                }
            
            }
            
        }
        
        

        return ans;
        
    }
};