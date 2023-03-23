/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void helper(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& res) {
    
        if (root == NULL) return;
        
        
        
        path.push_back(root->val);
        targetSum -= root->val;
        if (root->left == NULL && root->right == NULL && targetSum == 0) {
            res.push_back(path);
        }
        
        
        helper(root->left, targetSum, path, res);
        helper(root->right, targetSum, path, res);
        
        
        path.pop_back();
    }
    
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        
        vector<int> path;
        
        helper(root, targetSum, path, res);
        
        return res;
    }
};
