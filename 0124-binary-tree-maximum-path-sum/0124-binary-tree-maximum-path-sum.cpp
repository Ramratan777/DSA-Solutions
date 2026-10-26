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

    int path(TreeNode* root,int &res){
        if(root==nullptr){
            return 0;
        }
        int l=max(0,path(root->left,res));
        int r=max(0,path(root->right,res));
        res=max(l+r+root->val,res);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int res=root->val;
        path(root,res);
        return res;
    }
};