class Solution {

    /**
     * @param TreeNode $root
     * @return Integer
     */
    function maxLevelSum($root) {
        if (!$root) {
            return 0;
        }

        $queue = [$root];
        $level = 0;
        $maxSum = PHP_INT_MIN;
        $resultLevel = 0;

        while (!empty($queue)) {
            $level++;
            $levelSum = 0;
            $nextQueue = [];

            foreach ($queue as $node) {
                $levelSum += $node->val;

                if ($node->left) {
                    $nextQueue[] = $node->left;
                }
                if ($node->right) {
                    $nextQueue[] = $node->right;
                }
            }

            if ($levelSum > $maxSum) {
                $maxSum = $levelSum;
                $resultLevel = $level;
            }

            $queue = $nextQueue;
        }

        return $resultLevel;
    }
}