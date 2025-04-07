class Solution {
    fun canPartition(nums: IntArray): Boolean {
        val total = nums.sum()
        val target = total / 2

        return if (total % 2 != 0) false
        else BooleanArray(target + 1).also { sums ->
            sums[0] = true
            for (num in nums) for (i in target downTo num)
                sums[i] = sums[i] || sums[i - num]
        }[target]
    }
}