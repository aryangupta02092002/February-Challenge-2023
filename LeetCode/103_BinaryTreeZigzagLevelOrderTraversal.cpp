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
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        bool leftToright = true;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> row(sz);
            
            for(int i=0; i<sz; i++){
                TreeNode *node = q.front();
                q.pop();
                
                int idx = (leftToright) ? i : (sz-1-i);
                
                row[idx] = node->val;
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            leftToright = !leftToright;
            ans.push_back(row);
        }
        return ans;
    }
};
