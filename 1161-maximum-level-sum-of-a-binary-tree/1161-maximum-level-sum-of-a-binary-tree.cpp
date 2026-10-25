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
    vector<int> levelorder(TreeNode* root){
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sum=0;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                sum+=(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
    int maxLevelSum(TreeNode* root) {
        vector<int>levels=levelorder(root);
        int maxi=INT_MIN;
        int idx=-1;
        for(int i=0;i<(int)levels.size();i++){
            if(levels[i]>maxi){
                maxi=levels[i];
                idx=i;
            }
        }
        return idx+1;
    }
};