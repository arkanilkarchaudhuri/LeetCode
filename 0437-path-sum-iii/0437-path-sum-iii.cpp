class Solution {
private:
    int calculateSum(TreeNode* root, long long targetSum)
    {
        if(!root)
            return 0;
                
        return (targetSum == root->val) + calculateSum(root->left, targetSum-root->val) + calculateSum(root->right, targetSum-root->val);
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
                
        if(!root)
            return 0;
        
        return calculateSum(root, (long long)targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
        
    }
};