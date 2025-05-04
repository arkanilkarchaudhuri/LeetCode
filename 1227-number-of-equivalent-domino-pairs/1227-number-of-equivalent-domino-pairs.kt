class Solution {
    fun numEquivDominoPairs(dominoes: Array<IntArray>): Int {
        val count = IntArray(256)
        for ((a, b) in dominoes) {
            if (a < b) count[(a shl 4) or b]++
            else count[(b shl 4) or a]++
        }
        var result = 0
        for (n in count) {
            if (n > 1) {
                result += n * (n - 1) shr 1
            }
        }
        return result
    }
}