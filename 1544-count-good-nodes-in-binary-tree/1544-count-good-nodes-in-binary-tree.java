class Solution {
    public int goodNodes(TreeNode root) {
        if (root == null) return 0;

        int numGoodNodes = 0;
        Deque<Pair<TreeNode, Integer>> stack = new ArrayDeque<>();
        stack.push(new Pair<>(root, Integer.MIN_VALUE));

        while (!stack.isEmpty()) {
            Pair<TreeNode, Integer> current = stack.pop();
            TreeNode node = current.getKey();
            int maxVal = current.getValue();

            if (node.val >= maxVal) {
                numGoodNodes += 1;
                maxVal = node.val;
            }

            if (node.right != null) stack.push(new Pair<>(node.right, maxVal));
            if (node.left != null) stack.push(new Pair<>(node.left, maxVal));
        }

        return numGoodNodes;
    }
}