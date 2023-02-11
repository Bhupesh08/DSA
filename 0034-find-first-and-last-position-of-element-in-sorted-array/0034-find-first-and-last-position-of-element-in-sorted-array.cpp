class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res;
        
        int n = nums.size();
        
        if(n==0) {
            res.push_back(-1);
            res.push_back(-1);
            
            return res;
        }
        
        int l1=-1, r1=n;
        
        while(r1>l1+1) {
            int mid = l1 - (l1-r1)/2;
            if(nums[mid] < target) {
                l1 = mid;
            } else {
                r1 = mid;
            }
        }
        
        if(l1+1 < n && nums[l1+1]==target) res.push_back(l1+1);
        else res.push_back(-1);

        
        int l2=-1, r2=n;
        
        while(r2>l2+1) {
            int mid = l2 - (l2-r2)/2;
            if(nums[mid] <= target) {
                l2 = mid;
            } else {
                r2 = mid;
            }
        }
        
        if(r2-1 >= 0 && nums[r2-1]==target) res.push_back(r2-1);
        else res.push_back(-1);
        
        return res;
        
    }
    
    
};

