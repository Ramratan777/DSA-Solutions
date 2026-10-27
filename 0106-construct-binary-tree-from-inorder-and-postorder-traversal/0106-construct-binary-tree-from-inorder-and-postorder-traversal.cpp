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
    TreeNode* build(vector<int>&inorder,vector<int>&postorder,int left,int right,int &postidx){
        if(left>right){
            return nullptr;
        }
        int rootval=postorder[postidx];
        TreeNode* node=new TreeNode(rootval);
        postidx--;
        int mid=mp[rootval];
        
        node->right=build(inorder,postorder,mid+1,right,postidx);
        node->left = build(inorder,postorder,left,mid-1,postidx);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<(int)inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int n=inorder.size();
        int postidx=n-1;
        return build(inorder,postorder,0,n-1,postidx);
    }
};