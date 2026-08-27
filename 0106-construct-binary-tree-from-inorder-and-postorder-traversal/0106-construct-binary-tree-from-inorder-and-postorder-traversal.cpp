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

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int instart,int inend,int poststart,int postend,int& idx){
    if(instart>inend) return NULL;
    
    int rootval=postorder[postend];
    int i=instart;

   while(i<=inend && inorder[i] != rootval){
    i++;
    }


    int leftsize=i-instart;
    int rightsize=inend-i;

    TreeNode* root=new TreeNode(rootval);

    root->left=solve(inorder,postorder,instart,i-1,poststart,poststart+leftsize-1,idx);
    root->right=solve(inorder,postorder,i+1,inend,postend-rightsize,postend-1,idx);

    return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n=inorder.size();
    int idx=0;

    int instart=0;
    int inend=n-1;

    int poststart=0;
    int postend=n-1;

    return solve(inorder,postorder,instart,inend,poststart,postend,idx);

    
    }
};