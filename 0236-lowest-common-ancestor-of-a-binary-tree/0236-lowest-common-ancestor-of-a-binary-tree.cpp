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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(root==NULL) return NULL;
    
    if(root==p || root==q) return root;

    TreeNode* leftnod=lowestCommonAncestor(root->left,p,q);
    TreeNode* rightnod=lowestCommonAncestor(root->right,p,q);

    if(leftnod!=NULL && rightnod!=NULL) return root;
    
    if(leftnod!=NULL && rightnod==NULL) return leftnod;
    if(leftnod==NULL && rightnod!=NULL) return rightnod;

    return 0;
    }
};