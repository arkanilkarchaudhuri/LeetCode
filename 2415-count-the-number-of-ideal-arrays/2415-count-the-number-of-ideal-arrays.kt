import java.math.BigInteger

class Solution {
    private val cache = HashMap<Int, Int>()

    fun idealArrays(n: Int, maxValue: Int): Int {
        var answer = 0
        for (i in 1..maxValue) {
            answer = (answer + dfs(n, maxValue, i, 1)) % MOD
        }
        return answer
    }

    private fun dfs(n: Int, maxValue: Int, start: Int, i: Int): Int {
        val cached = cache[(start shl 16) or i]
        if (cached != null) {
            return cached
        }

        var count = C( i - 1, n - 1)

        if (i < n) {
            for (k in 2..maxValue / start) {
                count = (count + dfs(n, maxValue, start * k, i + 1)) % MOD
            }
        }

        cache[(start shl 16) or i] = count

        return count
    }

    private fun C(k: Int, n: Int): Int {
        val cached = Ckn[(k shl 16) or n]
        if (cached != null) {
            return cached
        }

        val newValue = (factorial[n] / (factorial[k] * factorial[n - k])).mod(BIG_MOD).toInt()
        Ckn[(k shl 16) or n] = newValue
        return newValue
    }

    companion object {
        val MOD: Int = 1_000_000_007
        val BIG_MOD: BigInteger = BigInteger.valueOf(1_000_000_007L)
        private val Ckn = HashMap<Int, Int>()

        val factorial = Array(10_001) { BigInteger.ZERO }
        init {
            factorial[0] = BigInteger.ONE
            for (i in 1 until factorial.size) {
                factorial[i] = (factorial[i - 1] * BigInteger.valueOf(i.toLong()))
            }
        }
    }
}