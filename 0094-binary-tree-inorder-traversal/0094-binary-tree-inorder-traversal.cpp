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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        stack<TreeNode*> s;
        while(true){
            if(root) {
                s.push(root);
                root = root->left;
            }
            else {
                if(s.empty()) break;
                root = s.top();
                s.pop();
                v.push_back(root->val);
                root = root->right;
            }
        }
        return v;
    }
};