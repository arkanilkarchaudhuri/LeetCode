class Solution {
    var str = "a"
    fun kthCharacter(k: Int): Char {
        solve(k, str)
        return str[k -1]
    }
    fun solve(k: Int, s: String){
        if (s.length >= k) return
        var temp = ""
        for (i in 0 until s.length) {
            temp += s[i] + 1
        }
        str += temp
        solve(k, str)
    }
}