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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        int width = 0;
        
        while(!q.empty()) {
            int size = q.size();
            int leftIndex, rightIndex;
            
            for(int i=0; i<size; i++) {
                auto it = q.front();
                q.pop();
                
                TreeNode* curr = it.first;
                long index = it.second;
                
                if(i==0) leftIndex = index;
                if(i==size-1) rightIndex = index;
                
                if(curr->left) {
                    q.push({curr->left, 2*(index-leftIndex) + 1});
                }
                
                if(curr->right) {
                    q.push({curr->right, 2*(index-leftIndex) + 2});
                }
            }
            
            width = max(width, rightIndex - leftIndex + 1);
        }
        
        return width;
    }
};