class Solution {
    fun longestPalindrome(ws: Array<String>): Int {
        val codea = 'a'.toInt()
        val size = 26 
        val count = Array(size) { IntArray(size) }        
        
        for (i in 0 until ws.size) {
            val w = ws[i]
            val a = w[0].toInt() - codea
            val b = w[1].toInt() - codea
            ++ count[a][b]
        }

        var result = 0
        var odd = false
        
        for (i in 0 until size) {
            
            if (count[i][i] % 2 == 1) {
                odd = true
            }
            
            result += 4 * (count[i][i] / 2)
            
            for (j in i + 1 until size) {
                result += 4 * minOf(count[i][j], count[j][i])
            }
        }
        
        if (odd) result += 2
        
        return result 
    }
}