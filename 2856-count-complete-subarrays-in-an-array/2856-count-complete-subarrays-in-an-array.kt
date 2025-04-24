class Solution {
    fun countCompleteSubarrays(nums: IntArray): Int {
        val seen = IntArray(2001)
        var totalCount = 0
        for (num in nums) {
            if (seen[num]++ == 0) {
                totalCount++
            }
        }
        seen.fill(0)
        val n = nums.size
        var left = 0
        var count = 0
        var result = 0
        for (right in 0 until n) {
            if (seen[nums[right]]++ == 0) {
                count++
            }
            while (count == totalCount) {
                if (--seen[nums[left]] == 0) {
                    count--
                }
                left++
            }
            result += left
        }
        return result
    }
}