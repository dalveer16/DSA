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
    TreeNode* tmp;

    TreeNode* removeLeafNodes(TreeNode* root, int tar) {
        if(root->left != NULL){
            tmp = removeLeafNodes(root->left,tar);
            if(tmp == NULL) root->left = NULL; 
        }
        if(root->right != NULL){
            tmp = removeLeafNodes(root->right,tar);
            if(tmp == NULL) root->right = NULL;
        }
        if(root->val == tar && root->left == NULL && root->right == NULL) root=NULL;
        return root; 
    }
};
