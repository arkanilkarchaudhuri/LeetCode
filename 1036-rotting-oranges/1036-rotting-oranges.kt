class Solution {

    data class Point(val i: Int, val j: Int)
    data class Node(val point: Point, val minute: Int)

    fun orangesRotting(grid: Array<IntArray>): Int {
        val rottens = LinkedList<Node>()

        for (i in 0 until grid.size) {
            for (j in 0 until grid[0].size) {
                if (grid[i][j] == 2) {
                    rottens.offer(Node(Point(i, j), 0))
                }
            }
        }

        var ans = 0
        while(rottens.isNotEmpty()) {
            val rotten = rottens.poll()
            val i = rotten.point.i
            val j = rotten.point.j
        
            if (i + 1 < grid.size && grid[i + 1][j] == 1) {
                rottens.offer(Node(Point(i + 1, j), rotten.minute + 1))
                grid[i + 1][j] = 2
            }
            if (j + 1 < grid[0].size && grid[i][j + 1] == 1) {
                rottens.offer(Node(Point(i, j + 1), rotten.minute + 1))
                grid[i][j + 1] = 2
            }
            if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                rottens.offer(Node(Point(i - 1, j), rotten.minute + 1))
                grid[i - 1][j] = 2
            }
            if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                rottens.offer(Node(Point(i, j - 1), rotten.minute + 1))
                grid[i][j - 1] = 2
            }
            ans = rotten.minute
        }

        
        for (i in 0 until grid.size) {
            for (j in 0 until grid[0].size) {
                if (grid[i][j] == 1) {
                    return -1
                }
            }
        }

        
        return ans

    }
}