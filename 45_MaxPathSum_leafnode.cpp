// From leaf node to leaf node

class Solution {
public:
    int solve(Node *root, int &res) {
        if (root == NULL) {
            return 0;
        }
        int l = solve(root->left, res);
        int r = solve(root->right, res);

        if (!root->left && !root->right)
            return root->data;

        if (!root->left)
            return root->data + r;

        if (!root->right)
            return root->data + l;

        int temp = root->data + max(l, r);
        int ans = root->data + l + r;
        res = max(res, ans);
        return temp;
    }

    int maxPathSum(Node *root) {
        int res = INT_MIN;
        int x = solve(root, res);
        if (!root->left || !root->right) {
            res = max(res, x);
        }
        return res;
    }
};
