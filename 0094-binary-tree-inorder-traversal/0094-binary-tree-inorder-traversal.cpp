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
//     private:
//     void helper(TreeNode* root, vector<int> &res) {
    
//     if(root==NULL) return;
    
//     helper(root->left, res);
        
//     res.push_back(root->val);
    
//     helper(root->right, res);
// }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if(root == NULL) return res;
        
        stack<TreeNode*> st;
        TreeNode* node = root;
        
        while(true) {
            //Pushing the left part till it doesn't become NULL
            if(node != NULL) {
                st.push(node);
                node = node->left;
            } 
            //if it has become NULL, then the top() is pointing to the element that has to come in Inorder
            else {
                if(st.empty()) break;   //If Node == NULL and stack has become empty -> we are done 
                
                node = st.top();
                st.pop();
                res.push_back(node->val);
                
                //Traverse the right part
                node = node->right;
            }
        }
        
        
        
        return res;
    }
};