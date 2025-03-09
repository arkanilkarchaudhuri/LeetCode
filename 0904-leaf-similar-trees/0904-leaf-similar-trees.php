/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($val = 0, $left = null, $right = null) {
 *         $this->val = $val;
 *         $this->left = $left;
 *         $this->right = $right;
 *     }
 * }
 */
class Solution {

    /**
     * @param TreeNode $root1
     * @param TreeNode $root2
     * @return Boolean
     */
    function leafSimilar($root1, $root2) {
        $leaves1 = [];
        $this->getLeaves($root1, $leaves1);

        $leaves2 = [];
        $this->getLeaves($root2, $leaves2);

        return $leaves1 === $leaves2;
    }

    private function getLeaves($root, &$leaves)
    {
        if ($root === null) {
            return;
        }

        if ($root->left === null && $root->right === null) {
            $leaves[] = $root->val;
        }

        $this->getLeaves($root->left, $leaves);
        $this->getLeaves($root->right, $leaves);
    }
}