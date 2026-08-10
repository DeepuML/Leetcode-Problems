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
    bool solve(TreeNode* root, long long minval ,long long maxval){
       if(root==NULL){
        return true;
       }
        //  boundary check
       if(root->val <= minval || root->val>=maxval){
            return false;
       }
        //  left subtree
        bool left = solve(root->left, minval,root->val);
        // right subtree
        bool right = solve(root->right, root->val, maxval);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};