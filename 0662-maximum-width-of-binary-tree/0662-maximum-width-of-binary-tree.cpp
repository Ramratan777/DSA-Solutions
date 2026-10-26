class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            long long start = q.front().second;
            long long l = 0, r = 0;

            for (int i = 0; i < n; i++) {
                auto [node, idx] = q.front();
                q.pop();

                idx -= start;

                if (i == 0) {
                    l = idx;
                }

                if (i == n - 1) {
                    r = idx;
                }

                if (node->left) {
                    q.push({node->left, 2 * idx + 1});
                }

                if (node->right) {
                    q.push({node->right, 2 * idx + 2});
                }
            }

            ans = max(ans, r - l + 1);
        }

        return (int)ans;
    }
};