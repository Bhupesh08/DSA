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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        map<int, map<int, multiset<int>>> nodes;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            TreeNode* curr = it.first;
            int line = it.second.first;
            int level = it.second.second;
            
            nodes[line][level].insert(curr->val);
            
            if(curr->left) q.push({curr->left, {line-1, level+1}});
            if(curr->right) q.push({curr->right, {line+1, level+1}});

        }
        
        vector<vector<int>> res;
        
        for(auto it: nodes) {
            vector<int> col;
            for(auto mpp: it.second) {
                col.insert(col.end(), mpp.second.begin(), mpp.second.end());
            }
            res.push_back(col);
        }
        
        return res;
        
    }
};