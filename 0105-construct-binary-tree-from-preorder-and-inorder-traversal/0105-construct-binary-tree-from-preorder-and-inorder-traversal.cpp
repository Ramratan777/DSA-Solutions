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
    map<int,int>mp;
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int &preidx,int left,int right){
        if(left>right){
            return nullptr;
        }
        int rootval=preorder[preidx];
        TreeNode* root=new TreeNode(rootval);
        preidx++;
        int mid=mp[rootval];
        root->left = build(preorder,inorder,preidx,left,mid-1);
        root->right=build(preorder,inorder,preidx,mid+1,right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<(int)inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int preidx=0;
        return build(preorder,inorder,preidx,0,inorder.size()-1);
    }
};