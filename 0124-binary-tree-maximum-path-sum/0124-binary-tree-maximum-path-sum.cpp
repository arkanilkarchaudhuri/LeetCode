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
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN; 
        helper(root, globalMax);
        return globalMax;
    }

private:
    
    int helper(TreeNode* node, int& globalMax) {
        if (node == nullptr) return 0;

       
        int leftMax = max(helper(node->left, globalMax), 0);
        int rightMax = max(helper(node->right, globalMax), 0);

      
        int localMax = node->val + leftMax + rightMax;

     
        globalMax = max(globalMax, localMax);

     
        return node->val + max(leftMax, rightMax);
    }
};