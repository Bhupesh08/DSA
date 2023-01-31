class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int, int> mpp;
        
        int n = nums.size();
        int sum = 0;
        int res = 0;
        mpp[0] = 1;
        
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(mpp.count(sum-k)) 
                res += mpp[sum-k]; 
            //     mpp[sum]++;
            // } else {
            //     mpp[sum]++;
            // }
            mpp[sum]++;
        }
        
        
        return res;
             
        
    }
};