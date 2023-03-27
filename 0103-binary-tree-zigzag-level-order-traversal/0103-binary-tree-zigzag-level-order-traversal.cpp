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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root == NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftToRight = true;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                //Finding the position to start filling level's value
                int index = (leftToRight) ? i : (size-1)-i;
                
                level[index] = curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }
            
            leftToRight = !leftToRight;
            res.push_back(level);
        }
        
        return res;
    }
};