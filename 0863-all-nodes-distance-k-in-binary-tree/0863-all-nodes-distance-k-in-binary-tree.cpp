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
    unordered_map<TreeNode*,TreeNode*>parent;

    void inorder(TreeNode* root){
    if(!root) return ;
    if(root->left!=NULL) parent[root->left]=root;
    inorder(root->left);

    if(root->right!=NULL) parent[root->right]=root;
    inorder(root->right);

    }

    void bfs(TreeNode* target, int k,vector<int>&result){
    queue<TreeNode*>q;
    q.push(target);

    unordered_set<int>visited;
    visited.insert(target->val);

    while(!q.empty()){
    int n=q.size();

    if(k==0) break;

    while(n--){
    TreeNode* cur=q.front();
    q.pop();
    // left
    if(cur->left!=NULL && !visited.count(cur->left->val)){
    q.push(cur->left);
    visited.insert(cur->left->val);
    } 
    // right
    if(cur->right!=NULL && !visited.count(cur->right->val)){
    q.push(cur->right);
    visited.insert(cur->right->val);
    } 

    if(parent.count(cur) && !visited.count(parent[cur]->val)){
    q.push(parent[cur]);
    visited.insert(parent[cur]->val);
    } 
    }
    k--;

    }
    while(!q.empty()){
    TreeNode* temp=q.front();
    q.pop();
    result.push_back(temp->val);
    }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int>result;
    
    inorder(root);

    bfs(target,k,result);
    return result; 
    }
};