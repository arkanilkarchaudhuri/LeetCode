/**
 * Definition for a binary tree node.
//  */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    TreeNode* findlastright(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    TreeNode* Helper(TreeNode* root) {
        if (root->left == nullptr) {
            return root->right;
        } 
        if (root->right == nullptr) {
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findlastright(root->left);
        lastRight->right = rightChild;

        return root->left; 
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (root->val == key) {
            return Helper(root);
        }

        TreeNode* curr = root;
        while (curr != nullptr) {
            if (key < curr->val) {
                if (curr->left != nullptr && curr->left->val == key) {
                    curr->left = Helper(curr->left);
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right != nullptr && curr->right->val == key) {
                    curr->right = Helper(curr->right);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};