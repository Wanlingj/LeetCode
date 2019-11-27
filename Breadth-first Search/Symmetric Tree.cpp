/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSym(TreeNode* a, TreeNode* b)
    {
        if(a==nullptr && b==nullptr)
            return true;
        return ((a&&b) && (a->val==b->val) && isSym(a->left,b->right) && isSym(a->right,b->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        return isSym(root->left,root->right);
    }
};
