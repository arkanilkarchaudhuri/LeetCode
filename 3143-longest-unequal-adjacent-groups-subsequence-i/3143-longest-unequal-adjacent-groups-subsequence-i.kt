class Solution {
    fun getLongestSubsequence(words: Array<String>, groups: IntArray): List<String> {
    var max=0
    val res= mutableListOf<String>()
    var currbit=-1
    var currlength=0
    for (i in words.indices){
        if(currbit==-1 || currbit+groups[i]==1){
            currbit=groups[i]
            currlength+=1
            if(currlength>max){
                res.add(words[i])
                max=currlength
            }
        }
    }

    return res
    }
}