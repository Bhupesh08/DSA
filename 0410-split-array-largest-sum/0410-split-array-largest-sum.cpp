class Solution {
private:
    bool isGood(vector<int>& nums, int k, int maxSum) {
        int subarr = 0;
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(sum > maxSum) {
                subarr++;
                sum = nums[i];
            }
        }
        
        if(sum <= maxSum) {
            subarr++;
        }
        
        // cout << subarr << endl;
        
        return subarr <= k;
    }
    
    
    
public:
    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        //edge case number 1
        if(k==1) {
            return accumulate(nums.begin(), nums.end(), 0);
        }
        
        //edge case number 2
        if(k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        
        int l = *max_element(nums.begin(), nums.end()) - 1;
        int r = accumulate(nums.begin(), nums.end(), 0);
        
        while(r > l+1) {
            int mid = l - (l-r)/2;
            
            // cout << l << " " << mid << " " << r << " " << endl;
            if(isGood(nums, k, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        return r;
    }
};