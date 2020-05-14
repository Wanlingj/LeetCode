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
    bool isValidBST(TreeNode* root) {
        bool flagleft = true;
        bool flagright = true;
        TreeNode *p;
        if (!root) return true;
        
        if(root -> left)
        {
            p = root -> left;
            while (p -> right)
                p = p -> right;
            flagleft = (root->left->val < root->val) && isValidBST(root->left) && (p->val < root -> val);
        }
        if(root -> right)
        {
             p = root -> right;
            while (p -> left)
                p = p -> left;
            flagright = (root->right->val > root->val) && isValidBST(root->right) && (p->val > root -> val);
        }
        return flagleft && flagright;
    }
};
