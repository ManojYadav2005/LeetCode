class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL) return NULL;
    if(root->val==key) return helper(root);
    
    TreeNode* dummy=root;

    while(root){
    if(root->val>key){
    if(root->left!=NULL && root->left->val==key){
    root->left=helper(root->left);
    break;
    }
    else{
    root=root->left;
    }
    }
    else{
    if(root->right!=NULL && root->right->val==key){
    root->right=helper(root->right);
    break;
    }
    else{
    root=root->right; }
    }
    } 
    return dummy;
    }


    TreeNode*  helper(TreeNode* root){
    if(root->left==NULL){
    return root->right;
    }
    if(root->right==NULL) return root->left;

    TreeNode* lastchild=root->right;
    TreeNode* lastrit=lastright(root->left);
    lastrit->right=lastchild;
    return root->left;

    }   

    TreeNode* lastright(TreeNode* root){
    if(root->right==NULL) return root;
    return lastright(root->right);
    }
    
};