class Solution {
private:
    void helper(vector<int> nums, int k, int sum, vector<int> &op, vector<vector<int>> &res) {
        if(sum==0 && op.size()==k) {
            res.push_back(op);
            return;
        }   
        
        if(nums.empty()) return;
        
        vector<int> op1 = op;
        vector<int> op2 = op;
        
        if(nums[0] <= sum) {
            op1.push_back(nums[0]);
        } else return;
        
        int val = nums[0];
        nums.erase(nums.begin() + 0);
        
        helper(nums, k, sum-val, op1, res);
        helper(nums, k, sum, op2, res);

    }
    
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        vector<vector<int>> res;
        
        vector<int> op;
        
        helper(nums, k, n, op, res);
        
        return res;
    }
};