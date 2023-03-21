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
// private:
//     void helper(TreeNode* root, vector<int> &res) {
    
//     if(root==NULL) return;
    
    
//     res.push_back(root->val);
    
//     helper(root->left, res);
    
//     helper(root->right, res);
// }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if(root == NULL) return res;
        
        stack<TreeNode*> st;
        
        st.push(root);
         
        while(!st.empty()) {
            TreeNode* current = st.top();
            res.push_back(current->val);
            st.pop();
            
            if(current->right) st.push(current->right);
            if(current->left) st.push(current->left);
        }
    
        return res;
    }
};