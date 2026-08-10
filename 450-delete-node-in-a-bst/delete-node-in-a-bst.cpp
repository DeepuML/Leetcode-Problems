class Solution {
public:

    TreeNode* findlastright(TreeNode* root) {
        if(root->right == NULL) {
            return root;
        }
        return findlastright(root->right);
    }

    TreeNode* helper(TreeNode* root) {
        // Case 1: no left child
        if(root->left == NULL) {
            return root->right;
        }
        // Case 2: no right child
        if(root->right == NULL) {
            return root->left;
        }
        // Case 3: both children exist
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findlastright(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) {
            return NULL;
        }
        // Root itself is the node to delete
        if(root->val == key) {
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root != NULL) {
            if(root->val > key) {
                if(root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else {
                if(root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};