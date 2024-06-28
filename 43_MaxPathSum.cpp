// From any node to any node
// Question Link :- https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Binary Tree Maximum Path Sum

// T.C = O(n)
// S.C = O(n)

int solve(TreeNode* root,int& res) {
    if(root==nullptr) {
        return 0;
    }
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    
    int temp=max( max(l,r) + root->val, root->val);
    int ans = max(temp, l+r+root->val);
    res=max(res,ans);
    
    return temp;
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
    int res=INT_MIN;
    solve(root,res);
    return res; 
    }
};