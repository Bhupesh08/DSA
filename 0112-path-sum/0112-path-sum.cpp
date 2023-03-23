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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        //Base case, return false because we moved further the leaf node and target was not achieved.
        if(root == NULL) return false;
        
        //decrease the value of targetsum for the next node
        targetSum -= root->val;
        
        //If the  node at which we are is the leaf node and the targetSum has become zero
        //Return true as answer has been found
        if(root->left == NULL && root->right == NULL && targetSum == 0) return true;
        
        //Check the leftSubTree and rightSubTree for the node for the node
        bool leftPath = hasPathSum(root->left, targetSum);
        bool rightPath = hasPathSum(root->right, targetSum);
        
        //remove the current node's value
        targetSum += root->val;
        
        //OR because we only need one path, so one true is enough to return the result as TRUE
        return leftPath || rightPath;
    }
};
