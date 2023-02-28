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
    string helper(TreeNode *root, vector<TreeNode*> &ans, map<string, int> &m){
        if(root == NULL){
            return " ";
        }
        string left = helper(root->left, ans, m);
        string right = helper(root->right, ans, m);
        
        string curr = to_string(root->val) + " " + left + " " + right;
        
        auto it = m.find(curr);
        if(it != m.end() && it->second == 1){
            ans.push_back(root);
        }
        m[curr]++;
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        map<string, int> m;
        helper(root, ans, m);
        return ans;
    }
};
