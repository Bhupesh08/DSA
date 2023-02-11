class Solution {
public:
    //we will use binary search to solve this problem
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res;
        
        int n = nums.size();
        
        //In case null vector is given, the target will never exist and we will just return [-1,-1]
        if(n==0) {
            res.push_back(-1);
            res.push_back(-1);
            
            return res;
        }
        
        
        //First binary search to get the index of the maximum element < target
        int l1=-1, r1=n;
        
        while(r1>l1+1) {
            int mid = l1 - (l1-r1)/2;
            if(nums[mid] < target) {
                l1 = mid; //l1 will point to that maximum element 
            } else {
                r1 = mid;
            }
        }
        
        //if l1 points to the maximum element < target, then l1 + 1 will point to the first occurrence (index) of target.
        if(l1+1 < n && nums[l1+1]==target) res.push_back(l1+1);
        else res.push_back(-1);

        
        
        //Second binary search to get the index of the minimum element > target 
        int l2=-1, r2=n;
        
        while(r2>l2+1) {
            int mid = l2 - (l2-r2)/2;
            if(nums[mid] <= target) {
                l2 = mid;
            } else {
                r2 = mid; //r2 will point to that minimum element 
            }
        }
        
        //if r2 points to the minimum element > target, then r2 - 1 will point to the last occurrence (index) of target.
        if(r2-1 >= 0 && nums[r2-1]==target) res.push_back(r2-1);
        else res.push_back(-1);
        
        return res;
        
    }
    
    
};

