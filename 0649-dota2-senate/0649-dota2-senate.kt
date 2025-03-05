class Solution {
    fun predictPartyVictory(senate: String): String {
        val radiantQueue = ArrayDeque<Int>()
        val direQueue = ArrayDeque<Int>()
        for (i in senate.indices) {
            if (senate[i] == 'R')
                radiantQueue.addLast(i)
            else
                direQueue.addLast(i)
        }
        while (!radiantQueue.isEmpty() && !direQueue.isEmpty()) {
            val rIndex = radiantQueue.removeFirst()
            val dIndex = direQueue.removeFirst()
            if (rIndex < dIndex)
                radiantQueue.addLast(rIndex + senate.length)
            else
                direQueue.addLast(dIndex + senate.length)
        }
        return if (!radiantQueue.isEmpty()) "Radiant" else "Dire"     
    }
}