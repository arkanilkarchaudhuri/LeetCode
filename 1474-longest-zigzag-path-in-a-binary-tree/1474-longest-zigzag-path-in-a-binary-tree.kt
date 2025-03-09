class Solution {
    var max = 0

    fun longestZigZag(root: TreeNode?): Int {
        root?.left?.let { left(it, 1) }
        root?.right?.let { right(it, 1) }
        return max
    }

    fun left(node: TreeNode?, length: Int) {
        node?.right?.let { right(it, length + 1) }
        node?.left?.let { left(it, 1) }
        max = maxOf(max, length)
    }

    fun right(node: TreeNode?, length: Int) {
        node?.left?.let { left(it, length + 1) }
        node?.right?.let { right(it, 1) }
        max = maxOf(max, length)
    }
}