class Solution {
    fun getDecimalValue(head: ListNode?): Int {
        var base = 1
        fun solve(node: ListNode?): Int {
            if (node == null) return 0
            var ans = solve(node.next) + node.`val` * base
            base *= 2
            return ans
        }
        return solve(head)
    }
}