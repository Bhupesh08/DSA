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
    int leftHeight(TreeNode* root) {
        int h = 0;
        TreeNode *curr = root;
        while(curr) {
            h++;
            curr = curr->left;
        }
        
        return h;
    }
    
    int rightHeight(TreeNode* root) {
        int h = 0;
        TreeNode *curr = root;
        while(curr) {
            h++;
            curr = curr->right;
        }
        
        return h;
    }
    
    
public:
    int countNodes(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        
        if(lh == rh) return pow(2, lh) - 1;
        
        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);
        
        return leftNodes + rightNodes + 1;
    }
};