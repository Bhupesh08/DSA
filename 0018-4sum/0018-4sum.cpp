class Solution {
public:
   
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        //we use 2 pointer only to solve this question
        //question is easy to solve if u understood 3 Sum properly.
        //just make sure that u are applying right conditions to prevent duplicates
        
        //or u could fucking use a set to prevent duplicates
        
        int n = nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; i++) {
            //preventing duplicate value for nums[i]
            if(i==0 || (i>0 && nums[i]!=nums[i-1])) {
                
                long long req = target - nums[i];
                
                int j = i+1;
                
                while(j<n-2) {
                
                    if(j==i+1 || (j>i+1 && nums[j]!=nums[j-1])) {
                    
                        int k = j + 1;
                        int l = n - 1;
                    
                        while(k<l) {
                        
                            if(nums[k] + nums[l] == req - nums[j]) {
                        
                                vector<int> v;
                                v.push_back(nums[i]);
                                v.push_back(nums[j]);
                                v.push_back(nums[k]);
                                v.push_back(nums[l]);
                        
                                res.push_back(v);
                                
                                //preventing duplicate value of nums[k] & nums[l]
                                while(k<l && nums[k]==nums[k+1]) k++;                                                         while(k<l && nums[l]==nums[l-1]) l--;
                            
                                k++;
                                l--;
                            
                            } else if(nums[k] + nums[l] < req - nums[j]) {
                                
                                k++;
                            
                            } else {
                                
                                l--;
                            }
                    
                        }
                    }
                    
                    //preventing duplicate value of nums[j]
                    while(j<n-2 && nums[j]==nums[j+1]) j++;
                    
                    j++;
                }
            }
        }
        
        
        
        return res;
    
    
    
    }
};