class Solution {
    fun findNumbers(nums: IntArray): Int {
        var evenCount = 0
        for(num in nums){
            if((Math.log10(num.toDouble()).toInt() +1) %2 == 0){
                evenCount++
            }
        }

        return evenCount
    }
}