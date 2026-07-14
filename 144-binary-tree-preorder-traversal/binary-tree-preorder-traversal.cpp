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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        // Base case: if the node is empty, return the empty vector
        if (root == nullptr) {
            return result;
        }
        
        // Preorder: Root -> Left -> Right
        
        // 1. Visit the Root
        result.push_back(root->val);
        
        // 2. Traverse the Left subtree
        vector<int> leftSubtree = preorderTraversal(root->left);
        result.insert(result.end(), leftSubtree.begin(), leftSubtree.end());
        
        // 3. Traverse the Right subtree
        vector<int> rightSubtree = preorderTraversal(root->right);
        result.insert(result.end(), rightSubtree.begin(), rightSubtree.end());
        
        return result;
    }
};