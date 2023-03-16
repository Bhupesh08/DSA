class Solution {
private:
    void helper(vector<int> candidates, int target, vector<int> &op, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(op);
            return;
        }
        
        if (candidates.empty()) {
            return;
        }
        
        vector<int> op1 = op;
        vector<int> op2 = op;
        
        if(candidates[0] <= target) {
            op1.push_back(candidates[0]);
        } else return;
        helper(candidates, target-candidates[0], op1, ans);
        
        
        candidates.erase(candidates.begin()+0);
        helper(candidates, target, op2, ans);
        
    }
    
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
       
        vector<int> op;
        
        sort(candidates.begin(), candidates.end());
        
        helper(candidates, target, op, ans);
        
        return ans;
    }
};
