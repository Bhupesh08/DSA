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
    bool helper(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        
        if(root1 == NULL || root2 == NULL) return false;
        
        bool lr = helper(root1->left, root2->right);
        bool rr = helper(root1->right, root2->left);
        
        return (root1->val == root2->val && lr && rr);

    }
    
public:
    bool isSymmetric(TreeNode* root) {
        
        bool res;
        
        TreeNode* root1 = root->left;
        TreeNode* root2 = root->right;
        
        res = helper(root1, root2);
        
        return res;
    }
};