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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root==NULL){
            return result;
        }
        
        queue<TreeNode *> Q;
       
        Q.emplace(root);
        
        while (!Q.empty()){
            vector<int> level;
            int size=Q.size();
            for (int i=0;i<size;i++ ){
                TreeNode* front = Q.front();
                level.push_back(front->val);
                Q.pop();
                if(front->left != NULL){
                    Q.emplace(front->left);
                }
                if(front->right !=NULL){
                    Q.emplace(front->right);
                }
                
            }
            result.push_back(move(level));
        }
        return result;
        
        
    }
   
};
