class Solution {
public:
    int solve(TreeNode* &root, TreeNode* &p, TreeNode* &q, TreeNode* &ans){        
        if(!root) return 0;        
        int a=0;
        a = solve(root->left, p, q, ans) + solve(root->right, p, q, ans);
        if(root == p || root == q) a++;
        if(a == 2 && ans == NULL) ans = root;
        return a; 
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        solve(root, p, q, ans);
        return ans;
    }
};